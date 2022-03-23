cmake_minimum_required(VERSION 3.0.0)
project(objektinio-programavimo-uzduotis VERSION 0.3.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O3)

add_executable(main src/main.cpp src/helper-functions.cpp src/helper-functions.h src/new-data-types.h src/input-output.cpp src/input-output.h src/timer.h)
