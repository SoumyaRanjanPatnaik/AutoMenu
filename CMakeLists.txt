cmake_minimum_required(VERSION 3.10.0)
project(automenulib)
add_library(
    menu SHARED
    src/automenu.hpp
    src/automenu.cpp
    )

add_executable(example_1 example/example_1.cpp)
add_executable(example_2 example/example_2.cpp)
target_link_libraries(example_1 menu)
target_link_libraries(example_2 menu)
