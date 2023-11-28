cmake_minimum_required(VERSION 3.26)
project(bintree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bintree
        binTree.cpp
        binTree.h
        linkQueue.h)
