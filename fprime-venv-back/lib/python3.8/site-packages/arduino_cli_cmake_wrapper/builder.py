""" Handles the setup and build of the arduino-cli test build

The core of the arduino-cli-wrapper runs arduino-cli with a test build and mines the output for the necessary build
steps for compiling Arduino programs generically. This module contains the functions for setting-up, running, and
capturing output from that build.

@author lestarch
"""
import logging
import subprocess

from pathlib import Path
from tempfile import TemporaryDirectory
from typing import Dict, List, Tuple, Union

from .types import Source, FauxBuildException


LOGGER = logging.getLogger(__name__)


def make_sketch(directory: Path, libraries: List[str]) -> Dict[Source, Path]:
    """Create a sketch folder with at least a C, C++, and assembly file

    Arduino must compile sketches and in order to determine the necessary compilation information we must create a
    sketch that uses each of these constructs for compilation. This function will generate a sketch using these
    constructs and return the mapping of the type extension (c, cpp, S) to the path to that created file

    Args:
        directory: directory to create the sketch within
        libraries: list of libraries to include in the sketch

    Returns:
        mapping between file extension string and temporary file
    """
    libraries = libraries if libraries else []
    mappings = {
        source: directory / f"{directory.name}.{ source.value }" for source in Source
    }
    # Create an empty source of each type
    for _, path in mappings.items():
        path.touch()
    # Create main sketch as an ino file such that it is a valid sketch
    with open(mappings.get(Source.INO), "w") as file_handle:
        include_set = "\n".join(f"#include <{library}.h>" for library in libraries)
        file_handle.write(include_set + "\nvoid setup() {}\nvoid loop() {}")
    return mappings


def compile_sketch(board: str, directory: Path, pass_through: Union[List[str], None] = None) -> Tuple[str, str]:
    """ Compile the sketch to product core and output text.

    This will compile a sketch directory and produce the necessary core archive and output text. This runs with the
    --clean flag to prevent cross-talk from any other builds in the form of cached build output. The board to compile
    against is passed in along with the directory containing the sketch. In order to produce all necessary information
    this command is run in verbose mode.

    Args:
        directory: sketch directory to compile
        board: compile board target FQBN
        pass_through: list of extra arguments to supply the arduino-cli
    Returns:
        tuple of raw standard out and standard error of the build
    """
    pass_through = pass_through if pass_through else []
    arguments = [
        "arduino-cli",
        "compile",
        "-v",
        "--clean",
        "-b",
        board,
    ] + pass_through + [str(directory)]
    LOGGER.debug("Invoking: %s", " ".join(arguments))

    process = subprocess.run(
        arguments,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    if process.returncode != 0:
        raise FauxBuildException(f"arduino-cli failed with return code: {process.returncode}", process.stderr)
    return process.stdout, process.stderr


def build(board: str, libraries: List[str], args: Union[List[str], None] = None) -> Tuple[Dict[Source, Path], str, str]:
    """ Run the test build and produce the raw build console output

    Runs the arduino build under the given constraints: board type, list of libraries needed from arduino, and the set
    of pass-through arguments to supply directly to the command invocation.

    Args:
        board: compile board target FQBN
        libraries: list of libraries to include in the sketch
        args: list of extra arguments to supply the arduino-cli
    Returns:
        tuple of raw standard out and standard error of the build
    """
    with TemporaryDirectory() as temporary_directory:
        temporary_path = Path(temporary_directory)
        mappings = make_sketch(temporary_path, libraries)
        stdout, stderr = compile_sketch(board, temporary_path, args)
    return mappings, stdout, stderr
