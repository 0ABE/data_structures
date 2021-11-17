# CMakeList.txt : CMake project for LinkedLists, include source and define
# project specific logic here.
#
# usage: cmake . -B out -G Ninja
#        cmake --build out
#

cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project ("SinglyLinkedLists")

# Add source to this project's executable.
add_executable (SinglyLinkedLists "main.cpp" 
                "SingleNode.cpp" "SingleNode.h" 
                "Reverser.cpp" "Reverser.h"
                "Testframe.cpp" "Testframe.h"
                "ListBuilder.cpp" "ListBuilder.h")

# TODO: Add tests and install targets if needed.
