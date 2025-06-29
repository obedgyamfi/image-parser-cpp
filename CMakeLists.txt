cmake_minimum_required(VERSION 3.16)
project(image-parser-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ⚠️ Make sure build type is respected
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose build type" FORCE)
endif()

# 💡 Explicit debug flags to ensure GDB gets line info
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Includes
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect sources
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

# Define the executable
add_executable(image-parser-cpp ${SOURCES})
