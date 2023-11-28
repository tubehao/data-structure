cmake_minimum_required(VERSION 3.26)
project(twotree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(twotree
        twotree.cpp
        twotree.h
        linkQueue.h
        linkStack.h
        linkQueue.h)
