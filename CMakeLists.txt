cmake_minimum_required(VERSION 2.8)

project(codx)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

file(GLOB headers "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB src "${CMAKE_SOURCE_DIR}/src/*.cpp")

include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} "${src}" "${headers}" "main.cpp")
