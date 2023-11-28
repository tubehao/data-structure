cmake_minimum_required(VERSION 3.26)
project(sequence_query)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sequence_query
        sequence_query.cpp
        sequence_query.h)
