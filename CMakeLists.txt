cmake_minimum_required(VERSION 2.8)

project(algo)

add_definitions(-std=c++14)

file(GLOB headers "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB src "${CMAKE_SOURCE_DIR}/src/*.cpp")

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} "${src}" "${headers}" "main.cpp")
