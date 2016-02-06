cmake_minimum_required(VERSION 3.3)
project(sdl_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sdl_game ${SOURCE_FILES})