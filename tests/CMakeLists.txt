cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -Wextra")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")
add_executable(test test.cpp)
