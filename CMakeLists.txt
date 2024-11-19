cmake_minimum_required(VERSION 3.13)
project(Bore-Sat C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

include("${CMAKE_CURRENT_LIST_DIR}/fprime/cmake/FPrime.cmake")
fprime_setup_included_code()
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
