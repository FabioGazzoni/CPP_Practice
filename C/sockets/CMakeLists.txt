cmake_minimum_required(VERSION 3.10)
project(sockets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -Wunreachable-code")

find_package(Threads REQUIRED)

add_executable(client src/client_main.c)
add_executable(server src/server_main.c)

add_library(utils STATIC src/utils.c)
target_include_directories(utils PUBLIC /src/inc)

set_target_properties(client PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
set_target_properties(server PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
target_link_libraries(client utils Threads::Threads)
target_link_libraries(server utils Threads::Threads)
