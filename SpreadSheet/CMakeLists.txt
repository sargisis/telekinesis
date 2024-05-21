cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SpreadSheetProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(SpreadSheetProject 
    ../Src/main.cpp 
    ../Src/SpreadSheet.cpp 
    Src/Cell.cpp
)

# Include directories
target_include_directories(SpreadSheetProject PUBLIC "${PROJECT_SOURCE_DIR}")
