cmake_minimum_required(VERSION 3.27)
project(klausur)

set(CMAKE_CXX_STANDARD 17)

add_executable(klausur main.cpp
        exceptions.h
        carRental.h
        carRental.cpp
        car.h
        car.cpp
        vwBus.h
        vwBus.cpp
        fordFocus.h
        fordFocus.cpp
        ferrariF40.h
        smallBus.h
        smallBus.cpp
        ferrariF40.cpp)
