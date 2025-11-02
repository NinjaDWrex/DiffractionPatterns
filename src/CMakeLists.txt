cmake_minimum_required(VERSION 3.10)
project(DiffractionPatterns CXX)

find_package(raylib CONFIG REQUIRED)

add_executable(DiffPatternsJoy main.cpp)
target_link_libraries(DiffPatternsJoy PRIVATE raylib)
