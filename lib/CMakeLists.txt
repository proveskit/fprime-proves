####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp"
    # "${CMAKE_CURRENT_LIST_DIR}/Adafruit_NeoPixel/rp2040_pio.h"
)

add_library(Adafruit_NeoPixel ${SOURCE_FILES})
target_include_directories(Adafruit_NeoPixel PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_NeoPixel")
