# This CMake file is intended to register project-wide objects.
# This allows for reuse between deployments, or other projects.

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components")
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/BroncoDeployment/")
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/OreDeployment/")
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PROVESDeployment/")
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/UartPROVES/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/BroncoDeployment/")
