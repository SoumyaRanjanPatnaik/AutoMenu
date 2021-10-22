cmake_minimum_required(VERSION 3.10.0)
project(automenulib)
add_library(
    menu SHARED
    src/automenu.hpp
    src/automenu.cpp
    )

add_executable(test test/test.cpp)
target_link_libraries(test menu)
