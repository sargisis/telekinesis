cmake_minimum_required(VERSION 3.15)

project(Queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(Queue QueueHeader/Queue.h QueueSrc/Queue.hpp QueueSrc/main.cpp)
