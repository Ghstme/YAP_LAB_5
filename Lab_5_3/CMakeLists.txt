cmake_minimum_required(VERSION 3.28)
project(Lab_5_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_5_3 main.cpp
        matrix.h
        matrix.tpp
        matrix_demo.cpp
        matrix_demo.h
)
