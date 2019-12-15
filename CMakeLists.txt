cmake_minimum_required(VERSION 3.15)
project(task6_sum_of_it_parts)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(task6_sum_of_it_parts
        src/main.cpp
        src/parts.cpp
        src/parts.h)
