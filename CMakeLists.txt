cmake_minimum_required(VERSION 3.28)
project(minimos_quadrados C)

set(CMAKE_C_STANDARD 11)

add_executable(minimos_quadrados main.c
        calculation.h
        display.c
        allocation.c
        calculation.c)
