cmake_minimum_required(VERSION 3.22)
project(Allapotgep_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Allapotgep_2_0
        allapotgep.hpp
        gtest_lite.h
        komment.cpp
        komment.hpp
        lyszamlalo.cpp
        lyszamlalo.hpp
        main.cpp
        memtrace.cpp
        memtrace.h
        split.cpp
        split.hpp)
