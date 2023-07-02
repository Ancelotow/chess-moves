cmake_minimum_required(VERSION 3.22)
project(chess_moves)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess_moves main.cpp chess.h chess.cpp)
