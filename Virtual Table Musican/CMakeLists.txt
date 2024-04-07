cmake_minimum_required(VERSION 3.15)

project(VirtualTable)

include_directories(../Headers)  

set(CMAKE_CXX_STANDARD 20)

add_executable(VirtualTable ../Src/main.cpp ../Headers/VT.h)
