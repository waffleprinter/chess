cmake_minimum_required(VERSION 3.29)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess src/main.cpp
        src/bitboard_utils.cpp
        headers/bitboard_utils.h
        src/board.cpp
        headers/board.h
        headers/move_gen.h
        src/move_gen.cpp
)

target_include_directories(chess PRIVATE ${CMAKE_SOURCE_DIR}/headers)
