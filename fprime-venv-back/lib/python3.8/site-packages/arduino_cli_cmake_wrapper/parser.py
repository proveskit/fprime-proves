""" Parsing functions to refine the arduino-cli output

This module contains the functions used to parse the arduino-cli output and refine it into something more useful for the
external application. This parsing is three steps:

    1. Sectioner: splits the output into the different sections as announced by arduino-cli
    2. Invocation filter: filters sections down into specific tool invocations
    3. Annotater: annotates section data for use upstream

@author lestarch
"""
import logging
from shutil import which
from typing import Dict, List, Tuple

from .util import safe_split, string_dictionary_of_list
from .types import Stage


LOGGER = logging.getLogger(__name__)


ANNOTATION_MAP = {
    "Detecting libraries used...": Stage.LIBRARY_DETECTION,
    "Generating function prototypes...": Stage.PROTOTYPES,
    "Compiling sketch...": Stage.COMPILATION,
    "Compiling libraries...": Stage.LIBRARIES,
    "Compiling core...": Stage.CORE,
    "Linking everything together...": Stage.LINK,
}


def sectioner(stdout: str) -> List[Tuple[str, List[str]]]:
    """ Section stdout into the arduino-cli indicated sections

    Create a list of sections (name, list of output lines) as announced by the arduino-cli. arduino-cli announces these
    sections with a line ending in "..." where the preceding text describes what is being done. These sections will be
    broken out into a list of (announcement, lines) tuples containing the output in-order.

    Args:
        stdout: raw standard output from the temporary build

    Returns:
        list of (announcement, section lines) tuples containing the in-order build section output
    """
    lines = [line.strip() for line in stdout.split("\n")]
    titles = filter(lambda enumeration: enumeration[1].endswith("..."), enumerate(lines))
    enumerated_titles = list(enumerate(titles))
    indexed_titles = [
        (title, start, dict(enumerated_titles).get(index + 1, (-1,))[0])
        for index, (start, title) in enumerated_titles
    ]
    return [(title, lines[start + 1:end]) for title, start, end in indexed_titles]


def invocation_filter(lines: List[str]) -> List[str]:
    """ Filters the lines to direct invocations

    arduino-cli records invocations of tools, but also reports standard output of those tools. This filter reduces the
    set of output lines into specifically those that are real invocations as defined by: a line where the line is a
    valid command line and the first token as parsed by the shell is an executable.

    Arg:
        lines: input lines to filter

    Returns:
        lines filtered to contain a tool invocation
    """
    return [
        line
        for line, shell_tokens in [(line, safe_split(line, ignore_errors=True)) for line in lines]
        if shell_tokens and which(shell_tokens[0])
    ]


def annotate(sections: List[Tuple[str, List[str]]]) -> List[Tuple[Stage, List[str]]]:
    """ Annotate the stage output with pre-defined stage type

    Annotate the sections with the pre-defined build stage that that section represents. UNUSED will annotate sections
    that are not used in the larger application

    Args:
        sections: sections of raw build steps
    Return:
        ordered and annotated build steps
    """
    return [
        (ANNOTATION_MAP.get(title, Stage.UNKNOWN), lines)
        for title, lines in sections
    ]


def parse(stdout: str) -> Dict[Stage, List[str]]:
    """ Parses the standard output of the arduino build into annotated sections

    Parse the standard output the arduino-cli into sections. These sections are then annotated with the section's role
    in the build process. These annotated sections are then placed in an in-order dictionary that represents a queryable
    set of build steps.

    Args:
        stdout: standard output from the test-build
    Return:

    """
    raw_sections = sectioner(stdout)
    sections = [(title, invocation_filter(lines)) for title, lines in raw_sections]
    annotated = annotate(sections)

    # Unknown title detection and warnings
    unknown_titles = [
        title for title, stage in
        zip(
            [title for title, _ in sections],
            [stage for stage, _ in annotated]
        )
        if stage == Stage.UNKNOWN
    ]
    if unknown_titles:
        LOGGER.warning("Unknown sections detected with titles: %s", ",".join(unknown_titles))
    build_stages = {stage: lines for stage, lines in annotated}
    LOGGER.debug("Detected build stages:\n\t%s", string_dictionary_of_list(build_stages))
    return build_stages
