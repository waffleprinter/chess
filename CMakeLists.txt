cmake_minimum_required(VERSION 3.29)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess src/main.cpp
        src/bitboardUtils.cpp
        headers/bitboardUtils.h
)
