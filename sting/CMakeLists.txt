cmake_minimum_required(VERSION 3.24)
project(sting)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_BUILD_TYPE "Debug")
add_executable(main main.cpp)

add_library(sting sting.cpp)
target_link_libraries(main sting)