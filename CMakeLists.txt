cmake_minimum_required(VERSION 3.7)
project(CircleDrawing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(CircleDrawing ${SOURCE_FILES})
target_link_libraries(CircleDrawing graph)