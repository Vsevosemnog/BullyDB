cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(BullyDB  VERSION 0.1)

#find_package(Catch2 REQUIRED)
add_subdirectory(lib/Catch2)
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)

#include(lib/Catch2)

#catch_discover_tests(tests)