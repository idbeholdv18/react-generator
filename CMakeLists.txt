cmake_minimum_required(VERSION 3.10)
project(ReactComponentGenerator)

set(CMAKE_CXX_STANDARD 17)

# Указываем Clang в качестве компилятора
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Используем Ninja
set(CMAKE_GENERATOR "Ninja")

# Создаём исполняемый файл
add_executable(ReactComponentGenerator src/main.cpp)