# cmake_minimum_required(VERSION <specify CMake version here>)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode main.cpp
        lt001356/Solution.h
        lt000122/Solution.h
        lt000973/Solution.h
        lt000008/Solution.h
        lt000031/Solution.h
        lt001122/Solution.h
        lt000402/Solution.h)