cmake_minimum_required(VERSION 3.23)
project(RubikCube)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubikCube main.cpp Assemble.cpp Assemble.h SmallCube.cpp SmallCube.h RubikCube.cpp RubikCube.h)
