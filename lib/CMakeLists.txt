set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/chess-library/include/chess.hpp"
)

add_library(chess-library ${SOURCE_FILES})
target_include_directories(chess-library PUBLIC "${CMAKE_CURRENT_LIST_DIR}/chess-library")
