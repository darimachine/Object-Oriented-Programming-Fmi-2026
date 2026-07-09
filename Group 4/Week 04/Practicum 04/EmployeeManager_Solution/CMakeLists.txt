cmake_minimum_required(VERSION 4.0)
project(EmployeeManager)

set(CMAKE_CXX_STANDARD 26)

add_executable(EmployeeManager main.cpp
        Employee.cpp
        Employee.h
        Department.cpp
        Department.h
        Company.cpp
        Company.h
        Utils.h)
