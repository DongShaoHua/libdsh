cmake_minimum_required(VERSION 3.8)
project(libdsh)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main/main.c src/main/dstr.c src/main/dstr.h src/test/testdstr.c src/test/testdstr.h)
add_executable(libdsh ${SOURCE_FILES})