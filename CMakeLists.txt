cmake_minimum_required(VERSION 3.25)
project(CSC340Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSC340Project
        Main.cpp
        Person.cpp
        Person.h
        Reservation.cpp
        Reservation.h
        Restaurant.cpp
        Restaurant.h
        Table.cpp
        Table.h
        Waiter.cpp
        Waiter.h)
