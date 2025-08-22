cmake_minimum_required(VERSION 3.10)
project(repaso_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_executable(pointers pointers.cpp)
add_executable(clases clases.cpp)
add_executable(herencias herencia.cpp)