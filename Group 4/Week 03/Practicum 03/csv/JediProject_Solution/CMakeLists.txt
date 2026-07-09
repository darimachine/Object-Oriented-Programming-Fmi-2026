cmake_minimum_required(VERSION 4.0)
project(JediProject)

set(CMAKE_CXX_STANDARD 26)

add_executable(JediProject main.cpp)

# Link the experimental library for std::print support
target_link_libraries(JediProject PRIVATE stdc++exp)