cmake_minimum_required(VERSION 3.30)
project(testC C)

set(CMAKE_C_STANDARD 23)

add_executable(testC main.c
        vector.h
        vector.c)
