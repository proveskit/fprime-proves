# -----------------------------------------
#  PCT2075 Temperature Sensor
# -----------------------------------------
set(PCT2075-SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_PCT2075/Adafruit_PCT2075.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_BusIO_Register.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_SPIDevice.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_I2CDevice.cpp"
)
add_library(Adafruit_PCT2075 ${PCT2075-SOURCE_FILES})
target_include_directories(Adafruit_PCT2075 PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_PCT2075")
target_include_directories(Adafruit_PCT2075 PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO")
