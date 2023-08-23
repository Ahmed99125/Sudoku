cmake_minimum_required(VERSION 3.23)
project(sudoku)

set(CMAKE_CXX_STANDARD 23)

add_executable(sudoku main.cpp Board.cpp Board.h Game.cpp Game.h)
