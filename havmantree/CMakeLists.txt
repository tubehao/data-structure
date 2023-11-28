cmake_minimum_required(VERSION 3.26)
project(havmantree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(havmantree
        havman.cpp
        havman.h
linkStack.h)
