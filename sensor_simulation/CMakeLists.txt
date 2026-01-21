cmake_minimum_required(VERSION 3.10)
project(Practicle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_subdirectory(devices)
add_subdirectory(app)
add_subdirectory(sensors)