cmake_minimum_required(VERSION 3.16)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include/Sorting)
set(SORTING_INCLUDES include/Sorting)
add_subdirectory(Tests)


