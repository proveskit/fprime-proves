set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/MicroChess.h"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/MicroChess.ino"
)

add_library(MicroChess ${SOURCE_FILES})
target_include_directories(MicroChess PUBLIC "${CMAKE_CURRENT_LIST_DIR}/MicroChess")