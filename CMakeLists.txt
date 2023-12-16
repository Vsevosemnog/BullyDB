cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(BullyDB  VERSION 0.1)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/include
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

#Add Catch2 Unit tests
find_package(Catch2 REQUIRED)

add_executable(main ${all_SRCS})
target_link_libraries(main PRIVATE Catch2::Catch2)

#target_link_libraries()