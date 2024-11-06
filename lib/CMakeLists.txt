set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/MicroChess.h"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/board.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/chessutil.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/game.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/move.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/options.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/pieces.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/MicroChess/stats.cpp"
)

add_library(MicroChess ${SOURCE_FILES})
target_include_directories(MicroChess PUBLIC "${CMAKE_CURRENT_LIST_DIR}/MicroChess")