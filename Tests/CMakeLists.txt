project(${PROJECT_NAME}_Test)

cmake_minimum_required(VERSION 3.16)

Include(FetchContent)

#Download Catch2 for unit testing
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.6)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/_deps/catch2-src/contrib")


include_directories(../${SORTING_INCLUDES})

#Tests
include(CTest)
include(Catch)
enable_testing()

#Create testcase for each .cpp file
file(GLOB test_cases *.cpp)
foreach(case_file ${test_cases})
    get_filename_component( case_name ${case_file} NAME_WE )
    set (case_name ${case_name})

    add_executable(${case_name} ${case_file})
    target_link_libraries(${case_name} PRIVATE Catch2::Catch2)
    target_link_libraries(${case_name}
            PRIVATE # pick one
            Sorting_${CMAKE_PROJECT_NAME})

    catch_discover_tests(${case_name})

endforeach()
