cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stack
        Stack.cpp
        Stack.h)
