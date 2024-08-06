"""Arduino Cmake toolchain leveraging ``arduino-cli`` via python wrapper script.

It does not intend to replace the ``arduino-cli`` tool, nor is it
intended to be a full featured IDE-like solution.

This project seeks to programmatically scrape up the necessary parts of
the compile and link calls from the ``arduino-cli`` tool, set CMake
variables, and allow a CMake project to roughly emulate the Arduino
compile process.

The goal is to make it possible to leverge the Arduino libraries in a
CMake-bound framework, for Arduino supported targets. If you just want
to compile a normal Arduino project from the command line, skip this
project and CMake altogether and just use the ``arduino-cli`` as
intended.

On the other hand, if you are trying to use a CMake-bound project as
the primary development process, you need a way to extract the working
compile process from the Arduino IDE and reformat it into a CMake
Toolchain.

E.g.: To compile an `F Prime <https://github.com/nasa/fprime>`_ project
for an Arduino target using Arduino libraries, you need a shim like
this to avoid hard dependence on the exact version or Arduino, Arduino
Core, and the specific versions of installed libraries.
"""
__version__ = '0.0.0'
