cmake_minimum_required(VERSION 3.0.0)
project(objektinio-programavimo-uzduotis VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp helper-functions.cpp helper-functions.h new-data-types.h input-output.cpp input-output.h)
