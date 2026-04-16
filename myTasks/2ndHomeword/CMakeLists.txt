cmake_minimum_required(VERSION 3.20)
project(CompanyTask)

set(CMAKE_CXX_STANDARD 23)

add_executable(CompanyTask
        main.cpp
        Company.cpp
        Company.h
        Department.cpp
        Department.h
        Employee.cpp
        Employee.h
        ErrorCode.h
)