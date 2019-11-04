cmake_minimum_required(VERSION 3.13)
project(PageRank)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -pedantic")

add_executable(PageRank main.cpp matrix.cpp matrix.hpp PageRank.cpp PageRank.hpp)
