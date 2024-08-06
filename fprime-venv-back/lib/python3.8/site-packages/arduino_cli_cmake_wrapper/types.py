""" Types and definitions for the arduino-cli-wrapper application """

from enum import Enum, auto
from typing import List, Protocol

class Source(Enum):
    """ Enumeration of the source file types """
    C = "c"
    CPP = "cpp"
    S = "S"
    INO = "ino"  # Arduino specific "sketch" entrypoint


class Stage(Enum):
    """ Enumeration of Build Stages """
    LIBRARY_DETECTION = auto()
    PROTOTYPES = auto()
    COMPILATION = auto()
    LIBRARIES = auto()
    CORE = auto()
    LINK = auto()
    UNKNOWN = auto()


class FilterProtocol(Protocol):
    """ Specifies the contract of the methods running filtering """
    def __call__(self, tokens: List[str], negate: bool = False) -> List[str]:
        pass

    @staticmethod
    def pass_all(tokens: List[str], negate: bool = False):
        """ Default implementation: pass-all filter """
        return [] if negate else tokens


class ArduinoCLIException(Exception):
    """ Base for arduino-cli exceptions"""
    pass


class FauxBuildException(ArduinoCLIException):
    """ Exception for failing the test build """

    def __init__(self, message: str, stderr: str):
        """ Initialize the exception give the string and standard error """
        self.console_errors = stderr
        super().__init__(message)

    def __str__(self):
        """ Get the string message"""
        return f"{super().__str__()}\n\t{self.verbose()}"

    def verbose(self) -> str:
        """ Verbose error message """
        message = "\n\t".join(self.console_errors.split("\n"))
        return message


class MissingInvocationException(ArduinoCLIException):
    """ Invocation on command-line is missing """
    def __init__(self, source: Source):
        """ Construct based on missing source """
        super().__init__(f"Failed to find invocation for: *.{source.value}")


class MissingStageException(ArduinoCLIException):
    """ Missing build section """
    def __init__(self, stage: Stage):
        """Missing build stage """
        super().__init__(f"Failed to find any output for build stage: {stage.value}")


class MultipleInvocationException(ArduinoCLIException):
    """ Invocation on command-line was found multiple times """
    def __init__(self):
        """ Construct based on missing source """
        super().__init__(f"Found multiple invocations")
