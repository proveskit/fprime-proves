# -----------------------------------------
#  INA219 Power Monitor 
# -----------------------------------------

set(INA219_SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_INA219/Adafruit_INA219.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_BusIO_Register.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_I2CDevice.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO/Adafruit_SPIDevice.cpp"
)

add_library(Adafruit_INA219 ${INA219_SOURCE_FILES})

target_include_directories(Adafruit_INA219 PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_INA219")
target_include_directories(Adafruit_INA219 PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Adafruit_BusIO")

# -----------------------------------------
#  Add More here! 
# -----------------------------------------