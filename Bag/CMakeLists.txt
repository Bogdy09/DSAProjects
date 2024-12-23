cmake_minimum_required(VERSION 3.22)
project(DSA_Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_Lab1 App.cpp
        Bag.cpp
        BagIterator.cpp
        ExtendedTest.cpp
        ShortTest.cpp)
