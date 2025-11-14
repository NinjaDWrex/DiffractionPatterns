cmake_minimum_required(VERSION 3.10)
project(DiffractionPatterns CXX)

find_package(raylib CONFIG REQUIRED)

add_executable(DiffPatternsModeller main/main.cpp)
target_link_libraries(DiffPatternsModeller PRIVATE raylib)
