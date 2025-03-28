cmake_minimum_required(VERSION 3.10)
project(ReactComponentGenerator)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_GENERATOR "Ninja")

include_directories(include)

add_executable(ReactComponentGenerator src/main.cpp src/generate_component.cpp)