cmake_minimum_required(VERSION 3.29)
project(MPointers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(MPointers main.cpp
        MPointer.h
        MPointerGC.h
        MPointerGC.cpp)
