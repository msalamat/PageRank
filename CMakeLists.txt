cmake_minimum_required(VERSION 3.13)
project(Assignment01)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(Assignment01 main.cpp PageRank.cpp PageRank.hpp)