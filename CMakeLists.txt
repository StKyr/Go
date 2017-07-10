cmake_minimum_required(VERSION 3.6)
project(Go)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        board.cpp
        board.h
        main.cpp
        player.h
        printer.cpp
        printer.h
        util.h)

add_executable(Go ${SOURCE_FILES})