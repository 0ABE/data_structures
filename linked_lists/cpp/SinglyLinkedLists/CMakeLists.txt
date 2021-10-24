# CMakeList.txt : CMake project for LinkedLists, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SinglyLinkedLists")

# Add source to this project's executable.
add_executable (SinglyLinkedLists "main.cpp" "Node.cpp" "Node.h" "Reverser.cpp" "Reverser.h" "ListBuilder.cpp" "ListBuilder.h")

# TODO: Add tests and install targets if needed.
