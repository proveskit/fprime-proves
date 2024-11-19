set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/chess-library/include/chess.hpp"
)

add_library(chess ${SOURCE_FILES})
target_include_directories(chess PUBLIC "${CMAKE_CURRENT_LIST_DIR}/chess-library")
