cmake_minimum_required(VERSION 3.27)
project(dsa_lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsa_lab2 App.cpp
        ExtendedTest.cpp
        ShortTest.cpp
        SetIterator.cpp
        Set.cpp)
