cmake_minimum_required(VERSION 3.0.0)
project(objektinio-programavimo-uzduotis VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O3)

add_executable(main src/main.cpp
        src/helpers/helper-functions.cpp
        src/output/output.cpp
        src/input/input.cpp
        src/testing/testing.cpp
        src/helpers/divide-file.cpp
        src/classes/student.cpp)
