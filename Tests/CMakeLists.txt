project(${PROJECT_NAME}_Test)

cmake_minimum_required(VERSION 3.16)


find_package(Catch2 QUIET)
if(NOT Catch2_FOUND)
    #Download Catch2 for unit testing
    Include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v2.13.6)
endif()

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/_deps/catch2-src/contrib")

#Tests
include(Catch)
enable_testing()

#Create testcase for each .cpp file
file(GLOB test_cases *.cpp)
foreach(case_file ${test_cases})
    get_filename_component( case_name ${case_file} NAME_WE )

    add_executable(${case_name} ${case_file})
    target_link_libraries(${case_name} PRIVATE Catch2::Catch2)
    target_link_libraries(${case_name} PRIVATE Sorting_${CMAKE_PROJECT_NAME})

    catch_discover_tests(${case_name})
endforeach()
