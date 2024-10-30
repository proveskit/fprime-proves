# -----------------------------------------
#  INA219 Power Monitor 
# -----------------------------------------

set(RV-3028_C7-SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/RV-3028_C7-Arduino_Library/src/RV-3028-C7.cpp")

add_library(RV-3028_C7-Arduino_Library ${RV-3028_C7-SOURCE_FILES})
target_include_directories(RV-3028_C7-Arduino_Library PUBLIC "${CMAKE_CURRENT_LIST_DIR}/RV-3028_C7-Arduino_Library")

# -----------------------------------------
#  Add More here! 
# -----------------------------------------