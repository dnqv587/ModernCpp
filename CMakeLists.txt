cmake_minimum_required(VERSION 3.22)
project(ModernCpp)

find_package(LLVM REQUIRED CONFIG)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CLANG_COVERAGE_COMPILE_FLAGS}" )

add_subdirectory(cpp20)
add_subdirectory(cpp17)
add_subdirectory(cpp14)
add_subdirectory(cpp11)