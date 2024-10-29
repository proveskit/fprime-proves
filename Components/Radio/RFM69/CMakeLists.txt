####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
# UT_SOURCE_FILES: list of source files for unit tests
#
####
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/RFM69.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/RFM69.cpp"
)

set(MOD_DEPS
  Fw/Logger
)

target_use_arduino_libraries("SPI" "RH_RF69")

register_fprime_module()
