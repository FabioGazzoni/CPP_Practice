cmake_minimum_required(VERSION 3.10)
project(socket)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(app)