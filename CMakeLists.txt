cmake_minimum_required(VERSION 3.10)

project(Algebra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/libs ${CMAKE_SOURCE_DIR}/excepts)

file(GLOB SOURCES src/*.cpp)

add_executable(AlgebraProject ${SOURCES})

target_compile_options(AlgebraProject PRIVATE -O0 -Wall -Wextra -pedantic)
