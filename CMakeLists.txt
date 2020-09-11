# cmake_minimum_required(VERSION <specify CMake version here>)
project(c C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(c SString.c)