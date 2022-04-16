cmake_minimum_required(VERSION 3.0.0)
project(objektinio-programavimo-uzduotis VERSION 0.5.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O3)

add_executable(main src/main.cpp
        src/helpers/helper-functions.cpp src/helpers/helper-functions.h
        src/classes/student.h
        src/output/output.cpp src/output/output.h
        src/classes/timer.h
        src/input/input.cpp src/input/input.h
        src/testing/testing.cpp src/testing/testing.h
        src/helpers/divide-file.cpp src/helpers/divide-file.h)
