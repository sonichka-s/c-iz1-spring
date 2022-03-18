project(tp_1_iz C CXX)

cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "--coverage")

add_subdirectory(src)
add_subdirectory(cmd)
add_subdirectory(tests)