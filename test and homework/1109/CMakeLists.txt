cmake_minimum_required(VERSION 3.26)
project(1109)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(1109
        linkQueue.h
        linkStack.h
        twotree.cpp
        twotree.h)
