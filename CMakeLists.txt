cmake_minimum_required(VERSION 3.3)
project(sdl_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

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

find_package(Doxygen)
option(BUILD_DOCUMENTATION "Build Doxygen Documentation" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.in)
    set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)
    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif()
