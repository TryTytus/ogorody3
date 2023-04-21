cmake_minimum_required(VERSION 3.23)
project(ogrody3)

set(CMAKE_CXX_STANDARD 98)

add_executable(ogrody3 main.cpp src/fruit.cpp src/fruit.hpp src/branch.cpp src/branch.hpp src/tree.cpp src/tree.hpp src/garden.cpp src/garden.hpp)
