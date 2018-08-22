#specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1)

macro(use_cxx11)
if (CMAKE_VERSION VERSION_LESS "3.1")
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif ()
else ()
set (CMAKE_CXX_STANDARD 11)
endif ()
endmacro(use_cxx11)

use_cxx11()
# Project's name
project(LIB_STL)


# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_PATH})


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/inc")
set(SRC_FILE ${SRC_FILE}
        ${PROJECT_SOURCE_DIR}/src/Heap.cpp
        ${PROJECT_SOURCE_DIR}/src/HeapTest.cpp
    )
add_library(mySTL SHARED ${SRC_FILE})

add_executable(testSTL ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(testSTL mySTL)
