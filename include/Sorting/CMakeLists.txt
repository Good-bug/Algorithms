project(Sorting_${PROJECT_NAME})

include_directories(../../)
file(GLOB src_files *.h)
add_executable(${PROJECT_NAME} main.cpp)
