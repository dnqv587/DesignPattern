cmake_minimum_required(VERSION 3.22)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 20)

link_directories(${PROJECT_SOURCE_DIR}/3rd/gtest/lib)
include_directories(${PROJECT_SOURCE_DIR}/3rd/gtest/include)
include_directories(${PROJECT_SOURCE_DIR}/)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src)
add_subdirectory(test)