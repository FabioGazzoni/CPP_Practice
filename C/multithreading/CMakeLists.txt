cmake_minimum_required(VERSION 3.10)
project(multithreading)

find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_executable(main src/main.c)

set_target_properties(main PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
target_link_libraries(main PRIVATE Threads::Threads)
