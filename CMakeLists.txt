cmake_minimum_required(VERSION 3.2.1)

project(programming_challenges)

add_executable(3nplus1 getting-started/3nplus1.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/getting-started/tests_3nplus1.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
