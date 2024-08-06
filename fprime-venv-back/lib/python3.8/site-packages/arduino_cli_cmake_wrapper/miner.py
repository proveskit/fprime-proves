""" Data mining operations on the build stage data

Handles the data mining operations on the output of the build stages.
"""
import logging
from functools import partial
from pathlib import Path
from typing import Callable, Dict, List, Protocol, Tuple, Union

from .types import FilterProtocol, Source, Stage, MissingStageException, MultipleInvocationException, ArduinoCLIException
from .util import safe_split, string_dictionary_of_list, match_any, match_all


LOGGER = logging.getLogger(__name__)


def real_source_names(source_mappings: Dict[Source, Path]):
    """ Get the real source names from the source map """
    return {
        source: value.name if source != Source.INO else f"{value.name}.cpp"
        for source, value in source_mappings.items()
    }


def filter_by_flags(flags: Dict[str, bool], tokens: List[str], negate=False) -> List[str]:
    """ Filter a set of tokens based on a set of flags

    Reduce the set of tokens to ensure that it does not include any of the matching flags, unless negate is specified
    then only the matching flags are exposed. Tokens is a list of tokens, and flags is a dictionary of the flag (e.g.
    -c) to a boolean indicating if the flag takes an argument.

    Args:
        flags: flag to argument boolean dictionary
        tokens: tokens to filter
        negate: restrict to matching flags

    Returns:
        list of filter tokens
    """
    def filterer(token: str, previous: Union[None, str]):
        """ Filtering function taking current and previous token """
        value = match_any(flags.keys(), token[:2])
        value = value or match_any(
            [
                flag for flag, check in flags.items()
                if (callable(check) and check(previous)) or (not callable(check) and check)
            ],
            previous[:2]
        )
        return not value if negate else value

    return [
        token
        for index, token in enumerate(tokens)
        if not filterer(token, tokens[max(0, index - 1)])
    ]


def filter_by_filenames(filenames: List[str], tokens: List[str], negate=False) -> List[str]:
    """ Filter a set of tokens based on a set of filenames

    Filter a list of tokens by a list of filenames. In normal operation these filenames are removed. If negate is
    specified then only those tokens are kept.

    Args:
        filenames: flag to argument boolean dictionary
        tokens: tokens to filter
        negate: restrict to matching filenames

    Returns:
        list of filter tokens
    """
    def filterer(item: str):
        """ Filterer that can also negate """
        value = match_any(filenames, item)
        return not value if negate else value
    filtered_tokens = [token for token in tokens if not filterer(token)]
    return filtered_tokens


def build_tokens(stages: Dict[Stage, List[str]], sources: Dict[Source, Path]) -> Tuple[Dict[Source, str], Dict[Source, List[str]], Dict[Source, List[str]]]:
    """ Detect command line build tokens for each source type

    Looks at the source build invocation for each file in the source mapping, and determines the command line arguments
    used for the build of that source file. The <source file>, <source_file>.o and -o flag proceeding the .o are all
    removed as these depend on the name of the source. The resulting tokens are split into three values: tool used for
    compiling the source, build tokens, and include directories. These are each indexed by source type.

    Args:
        stages: parsed and annotated build information
        sources: mapping of source type to test source used

    Return:
        tuple of dictionaries: source to compiler, source to include paths, and source to build flags
    """
    real_names = real_source_names(sources)
    source_lines = {
        source: identify_line(Stage.COMPILATION, stages, partial(match_all, [f"{real_names.get(source)}[ |$]"]))
        for source in Source
    }

    def cleaner(items: List[str]) -> List[str]:
        """ Cleans out -c -o <arg> and filename arguments """
        return filter_by_filenames(list(real_names.values()), filter_by_flags({"-c": False, "-o": True}, items))
    sorter = partial(filter_by_flags, {"-I": lambda item: item == "-I"})

    sorted_source_lines = {
        source: sort_line(line, cleaner, sorter)
        for source, line in source_lines.items()
    }
    tools = {source: sorted_source_lines[source][0] for source in Source}
    non_include_paths = {source: sorted_source_lines[source][1] for source in Source}
    include_paths = {
        source: [path.replace("-I", "") for path in sorted_source_lines[source][2] if path != "-I"]
        for source in Source
    }
    LOGGER.debug(f"Detected compilers:\n\t%s", "\n\t".join([f"{source}: {value}" for source, value in tools.items()]))
    LOGGER.debug(f"Detected include paths:%s", string_dictionary_of_list(include_paths))
    LOGGER.debug(f"Detected build flags:%s", string_dictionary_of_list(non_include_paths))

    return tools, include_paths, non_include_paths


def sketch_cache(stages: Dict[Stage, List[str]]) -> Path:
    """ Detect the sketch cache Arduino uses

    Detects the cache used by Arduino for compiling the core, generating precompiled headers, and other scratch work
    that this tool can borrow as output.

    Args:
        stages: stages of the build output
    Return:
        path to Arduino cache directory
    """
    core_lines = stages.get(Stage.CORE)
    if not core_lines:
        raise MissingStageException(Stage.CORE)

    core_tokens = [token for token in safe_split(core_lines[-1]) if token.endswith("core.a")]
    assert core_tokens, "Could not find core.a"
    core_archive = core_tokens[0]
    cache = Path(core_archive).parent.parent
    LOGGER.debug("Found Arduino sketch cache: %s", cache)
    return cache


def identify_line(stage: Stage, stages: Dict[Stage, List[str]], match: Callable[[str], bool], single: bool=True) -> str:
    stage_lines = stages.get(stage, [])
    matching_lines = [line for line in stage_lines if match(line)]
    if not matching_lines:
        raise MissingStageException(stage)
    if single and len(matching_lines) > 1:
        print("\n".join(matching_lines))
        raise MultipleInvocationException()
    return matching_lines[0]


def sort_line(line: str, clean: FilterProtocol = None, sort: FilterProtocol = None) -> Tuple[str, List[str], List[str]]:
    clean = clean if clean else FilterProtocol.pass_all
    sort = sort if sort else FilterProtocol.pass_all

    tokens = clean(safe_split(line))
    if not tokens:
        raise ArduinoCLIException("No tokens available")
    return (
        tokens[0],
        sort(tokens[1:]),
        sort(tokens[1:], negate=True)
    )


def identify_link_line(stages: Dict[Stage, List[str]], source_objects: List[str]) -> str:
    """ """
    link_line = identify_line(Stage.LINK, stages, partial(match_all, source_objects))
    LOGGER.debug("Linking line: %s", link_line)
    return link_line


def identify_archive_line(stages: Dict[Stage, List[str]]) -> str:
    """ """
    archive_line = identify_line(Stage.CORE, stages, partial(match_all, [r"core\.a"]), single=False)
    LOGGER.debug("Archive line: %s", archive_line)
    return archive_line


def link_tokens(stages: Dict[Stage, List[str]], sources: Dict[Source, Path]) -> Tuple[str, List[str], List[str], List[str]]:
    """"""
    object_names = [f"{name}.o" for name in real_source_names(sources).values()]
    link_line = identify_link_line(stages, object_names)

    def cleaner(items: List[str]) -> List[str]:
        """ Cleans out -c -o <arg> and filename arguments """
        return filter_by_filenames(object_names, filter_by_flags({"-o": True}, items))

    link_sorter = partial(filter_by_filenames, [r"\.o$", r"\.a$", r"^-l", "--start-group$", "--end-group$"])
    linker, link_flags, linkables = sort_line(link_line, cleaner, link_sorter)

    link_objects = filter_by_filenames([r"\.o$"], linkables, negate=True)
    link_libraries = filter_by_filenames([r"\.a$", r"^-l", "--start-group$", "--end-group$"], linkables, negate=True)

    LOGGER.debug(f"Detected linker: %s", linker)
    LOGGER.debug(f"Detected linker flags:\n\t%s", "\n\t".join(link_flags))
    LOGGER.debug(f"Detected link libraries:\n\t%s", "\n\t".join(link_libraries))
    LOGGER.debug(f"Detected link objects:\n\t%s", "\n\t".join(link_objects))
    return linker, link_flags, link_objects, link_libraries


def archive_tokens(stages: Dict[Stage, List[str]]) -> Tuple[str, List[str]]:
    archive_line = identify_archive_line(stages)
    archive_cleaner = partial(filter_by_filenames, [r"core\.a", r"\.o"])
    archiver, archive_flags, _ = sort_line(archive_line, archive_cleaner)
    assert _ == [], "Sort list not empty"

    LOGGER.debug(f"Detected archive tool: %s", archiver)
    LOGGER.debug(f"Detected archive flags:\n\t%s", "\n\t".join(archive_flags))
    return archiver, archive_flags


def post_link_lines(stages: Dict[Stage, List[str]], sources: Dict[Source, Path]) -> List[str]:
    """"""
    object_names = [f"{name}.o" for name in real_source_names(sources).values()]
    link_line = identify_link_line(stages, object_names)
    stage_lines = stages.get(Stage.LINK, [])
    post_links = stage_lines[stage_lines.index(link_line) + 1:]

    LOGGER.debug(f"Post link steps:\n\t%s", "\n\t".join(post_links))
    return post_links
