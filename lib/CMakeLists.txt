##
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/RV-3028_C7-Arduino_Library/src/RV-3028-C7.cpp"
)

add_library(RV-3028_C7-Arduino_Library ${SOURCE_FILES})
target_include_directories(RV-3028_C7-Arduino_Library PUBLIC "${CMAKE_CURRENT_LIST_DIR}/RV-3028_C7-Arduino_Library")