cmake_minimum_required(VERSION 3.3)
project(sdl_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)

#libraries
add_subdirectory(libs/libSDL2pp)

#project subdir
add_subdirectory(src)

set(SOURCE_FILES main.cpp)
add_executable(sdl_game ${SOURCE_FILES})

include(FindPkgConfig)

pkg_search_module(SDL2PP REQUIRED sdl2pp)

include_directories(${SDL2PP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} src ${SDL2PP_LIBRARIES})