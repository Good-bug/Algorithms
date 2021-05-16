cmake_minimum_required(VERSION 3.16)
project(Algorithms VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include/Sorting)
set(SORTING_INCLUDES include/Sorting)
add_subdirectory(Tests)


