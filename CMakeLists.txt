cmake_minimum_required(VERSION 3.10)
project(chess_engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(chess_engine main.cpp Board.cpp Board.h Utils.cpp Utils.h)