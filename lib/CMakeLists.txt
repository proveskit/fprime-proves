set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_VL6180X/Adafruit_VL6180X.cpp"
)

add_library(Adafruit_VL6180X ${SOURCE_FILES})
target_include_directories(Adafruit_VL6180X PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_VL6180X")