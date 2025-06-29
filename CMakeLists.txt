cmake_minimum_required(VERSION 3.16)
project(image-parser-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# output directives
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# include directives 
include_directories(${CMAKE_SOURCE_DIR}/include)

# source files 
file(GLOB_RECURSE SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp 
    ${CMAKE_SOURCE_DIR}/main.cpp
)

# executable target 
add_executable(image-parser-cpp ${SOURCES})
