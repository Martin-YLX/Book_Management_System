cmake_minimum_required(VERSION 3.26)
project(Book_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Book_Management_System main.cpp
        BookLink.h
        Person.h
        BookLink.cpp
        Book.cpp
        Person.cpp
        User.h
        User.cpp
        Read.cpp)
