cmake_minimum_required(VERSION 3.10)

project(Vector)  # Change 'Vector' to your project name

set(CMAKE_CXX_STANDARD 20)  # Set the C++ standard to 20

# Include directories
include_directories(VectorHeader)  # Assuming VectorHeader contains necessary header files
include_directories(VectorSrc)
# Add the source files to the executable
add_executable(Vector 
    VectorSrc/main.cpp 
    VectorHeader/Vector.h 
    VectorSrc/Vector.hpp
)
