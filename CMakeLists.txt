cmake_minimum_required(VERSION 3.16)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    project(Algorithms VERSION "0.0.0")
else ()
    project(Algorithms VERSION "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

message("project version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include/Sorting)
set(SORTING_INCLUDES include/Sorting)
add_subdirectory(Tests)


