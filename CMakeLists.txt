cmake_minimum_required(VERSION 3.8)
project(libdsh)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c dstr.c dstr.h)
add_executable(libdsh ${SOURCE_FILES})