cmake_minimum_required(VERSION 3.15)

project(Stack)

include_directories("../stack/StackHeader/Stack.h")

set(CMAKE_CXX_STANDARD 20)

add_executable(Stack StackHeader/Stack.h StackSrc/Stack.hpp StackSrc/main.cpp)
