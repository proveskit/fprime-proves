"""Harvest the Arduino CLI for compilation arguments.

This script harvests the command line arguments, compiler/linker
commands, and built archive from a build of a test INO file in Arduino.
This allows the program to know how arduino should compile C and C++
files.
"""
import argparse
import shutil
import sys
from pathlib import Path
from typing import List

import logging
import json
from functools import reduce
from typing import Any, Dict, Tuple


from .builder import build
from .parser import parse
from .miner import build_tokens, sketch_cache, link_tokens, post_link_lines, archive_tokens
from .types import Source, Stage

HELP_TEXT = """Tool used to parse settings from a compilation run of Arduino CLI.

This tool will run a test compilation and then mine that test compilation for build tools, flags and parameters, and
pre-compiled artifacts that can be used as-is in a follow-up build.
"""


def parse_arguments(arguments: List[str]) -> argparse.Namespace:
    """Parse input arguments to influence the execution.

    The script needs to know where to copy the core library into the
    build system. Additionally, the board target is needed in order to
    properly compile. These settings are parsed out of the command line
    input arguments using the argparse module.

    Args:
        arguments: command line argument list to be parsed

    Returns:
        Namespace containing parsed arguments
    """
    parser = argparse.ArgumentParser(description=HELP_TEXT)
    parser.add_argument(
        "--debug",
        action="store_true",
        default=False,
        help="Turn on debugging output"
    )
    parser.add_argument(
        "-b",
        "--board",
        type=str,
        help="Target board FQBN supplied to the arduino build",
        required=True,
    )
    parser.add_argument(
        "-d",
        "--detect-settings",
        action="store_true",
        help="Tell fprime-arduino to detect build settings",
        default=False,
    )
    parser.add_argument(
        "-g",
        "--generate-code",
        action="store_true",
        help="Tell fprime-arduino to build support code",
        default=False,
    )
    parser.add_argument(
        "-i",
        "--includes",
        action="store_true",
        help="Tell fprime-arduino to list include directories",
        default=False,
    )
    parser.add_argument(
        "-l",
        "--libraries",
        type=str,
        nargs="*",
        help="List of arduino libraries to use (e.g. Wire.h)",
        required=False,
    )
    parser.add_argument(
        "-c",
        "--copy",
        type=str,
        nargs="*",
        help="List of extra filenames to copy and remap to new directory in generate step",
        required=False,
    )
    parser.add_argument(
        "--properties",
        type=str,
        nargs="*",
        help="List of build properties to supply",
        required=False,
    )
    parser.add_argument(
        "-p",
        "--post-link",
        action="store_true",
        help="Generate post link steps",
        required=False,
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="Output destination for the pre-compiled arduino core",
        required=True,
    )
    parser.add_argument(
        "-j",
        "--json-file",
        type=Path,
        default=None,
        help="Path to JSON file to write. Default: stdout"
    )
    return parser.parse_args(arguments)


def convert_to_output(value: Any, remaps: Dict[str, str]) -> Any:
    """ Remap a value with the given string to string transformations

    Remaps a value with the input set of string to string mappings. Strings will "replace" the first token with the
    second in-order. Lists remap each child element recursively. Dictionaries remap the key and recursively remap the
    child values.

    Args:
        value: value to remap, works best if a string, list, or dictionary
        remaps: dictionary of original to new strings to remap
    Return:
        remapped value
    """
    def remapper(item: str) -> str:
        """ Function to remap a string using the remaps input """
        def remap_one(accumulation: str, remap: Tuple[str, str]) -> str:
            """ Remap for a single tuple """
            return accumulation.replace(remap[0], remap[1])
        return reduce(remap_one, remaps.items(), f"{item}")
    try:
        return {remapper(key): convert_to_output(value, remaps) for key, value in value.items()}
    except AttributeError:
        try:
            if isinstance(value, str):
                return remapper(value)
            return [convert_to_output(item, remaps) for item in value]
        except ValueError:
            return remapper(value)


def remap_output(data: Dict, output_directory: Path, cache_path: Path, test_files: Dict[Source, Path]) -> Dict:
    """ Remap output data by setting up remapping dictionary and then calling convert_to_output

    The given output data is remapped to remove python data types, replace the cache path with the destination output
    directory, and test files to <TARGET...> replacement tags. post-link also remaps output directory with
    <TARGET_DIRECTORY>.

    Args:
        data: data to remap
        output_directory: directory where cache will be copied
        cache_path: path to the original cache
        test_files: source-to-files used to build the sample
    Return:
        remapped data
    """
    mappings = {
        "Source.CPP": "CXX",
        "Source.C": "C",
        "Source.S": "ASM",
        "Source.INO": "INO",
        str(cache_path): str(output_directory),
        str(output_directory / f"{test_files[Source.INO].name}.elf"): "<TARGET_PATH>",
        str(output_directory / test_files[Source.INO].name): "<TARGET_PATH>",
        str(test_files[Source.INO].name): "<TARGET_NAME>"
    }

    # Full data conversion
    data = convert_to_output(data, mappings)

    # Single section conversions
    if "post" in data:
        data["post"] = convert_to_output(data["post"], {str(output_directory): "<TARGET_DIRECTORY>"})
    return data


def assemble_output_data(test_files: dict[Source, Path], stages: Dict[Stage, List[str]], detect: bool, include: bool, post_link: bool) -> Tuple[Dict, Path]:
    """ Assemble the output data via data mining

    Compiler, link, archival, and post link data is mined. It is then assembled into the output data object based on the
    options specified to control the output data.

    Args:
        test_files: source to file used to compile test
        stages: stages found in the build
        detect: detect build settings
        include: include paths
        post_link: create post-link steps

    Return:
        assembled data.
    """
    compilers, includes, build_flags = build_tokens(stages, test_files)
    linker, link_flags, link_objects, link_libraries = link_tokens(stages, test_files)
    archiver, archive_flags = archive_tokens(stages)
    post_link_steps = post_link_lines(stages, test_files)

    data = {}
    if detect:
        data["tools"] = {**compilers, "LINKER": linker, "AR": archiver}
        data["flags"] = {**build_flags, "LINKER_EXE": link_flags, "AR": archive_flags}
        data["objects"] = link_objects
        data["libraries"] = link_libraries
    if include:
        data["includes"] = includes
    if post_link:
        data["post"] = post_link_steps
    return data, sketch_cache(stages)


def main(arguments: List[str] = None):
    """Perform entrypoint functions."""
    try:
        arguments = parse_arguments(arguments)
        output_directory = Path(arguments.output)
        logging.basicConfig(level=logging.DEBUG) if arguments.debug else logging.basicConfig(level=logging.INFO)

        # Run the build
        test_file_map, stdout, stderr = build(arguments.board, arguments.libraries, [])

        # Parse the output into stages
        stages = parse(stdout)

        # Mine the data for various needed properties
        output_data, cache_path = assemble_output_data(
            test_file_map, stages, arguments.detect_settings, arguments.includes, arguments.post_link
        )

        # Remap the output data
        output_data = remap_output(output_data, output_directory, cache_path, test_file_map)
        output_data["arguments"] = sys.argv[1:]

        # Output the data as JSON
        with (open(arguments.json_file, "w") if arguments.json_file is not None else sys.stdout) as file_handle:
            json.dump(output_data, file_handle, indent=4)

        # Outputs the sketch cache for ingestion into larger build
        if arguments.generate_code:
            if output_directory.exists():
                shutil.rmtree(output_directory)
            shutil.copytree(cache_path, output_directory)

    except Exception as exc:
        print(f"[ERROR] {exc.__class__.__name__} occurred. {exc}", file=sys.stderr)
        raise
        return 1
    return 0
