cmake_minimum_required(VERSION 3.17)
project(sting)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_BUILD_TYPE "Debug")
add_executable(sting_main sting/main.cpp)
add_executable(Vector_main Vector/main.cpp)

add_library(sting sting/sting.cpp)
target_link_libraries(sting_main sting)