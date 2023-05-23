cmake_minimum_required(VERSION 3.25)
project(algoritmos_DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algoritmos_DS
        tests.cpp
        Sorting_Searching.cpp
        Sorting_Searching.h)

# Enlaza los archivos de prueba con la biblioteca de Google Test
target_link_libraries(algoritmos_DS PRIVATE gtest)