project(Sorting_${PROJECT_NAME})

include_directories(../../)
file(GLOB src_files *.h)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE .)
