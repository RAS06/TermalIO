cmake_minimum_required(VERSION 3.25)
project(TermalIO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TermalIO main.cpp StringReader.cpp StringReader.h)
