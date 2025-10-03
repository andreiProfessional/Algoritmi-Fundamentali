cmake_minimum_required(VERSION 4.0)
project(lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_1 main.cpp
        memorare/memorare.h
        memorare/memorare.cpp
        constante.h
        teste/teste.h
        teste/teste.cpp)