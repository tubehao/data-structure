cmake_minimum_required(VERSION 3.26)
project(MidCueTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MidCueTree
        linkQueue.h
        linkStack.h
        twotree.cpp
        twotree.h)
