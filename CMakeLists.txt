cmake_minimum_required(VERSION 3.10)

project(calc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic -Wshadow")

if(NOT APPLE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
endif()

include_directories(libs utils excepts)

file(GLOB SOURCES
    src/*.cpp
    main.cpp
)

add_executable(calc ${SOURCES})

target_compile_options(calc PRIVATE -g -Wall -Wextra -Wpedantic -Wshadow)
if(NOT APPLE)
    target_link_options(calc PRIVATE -fsanitize=address)
endif()
