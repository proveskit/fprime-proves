set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/chess/main.cpp"
)

add_library(chess ${SOURCE_FILES})
target_include_directories(chess PUBLIC "${CMAKE_CURRENT_LIST_DIR}/chess")
