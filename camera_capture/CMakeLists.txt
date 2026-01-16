cmake_minimum_required(VERSION 3.10)
project(camera_capture)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

find_package(OpenCV REQUIRED)

add_library(buffer src/buffer.cpp)
add_library(camera src/camera.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main buffer camera)

target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(buffer ${OpenCV_LIBS})
target_link_libraries(camera ${OpenCV_LIBS})