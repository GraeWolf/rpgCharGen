cmake_minimum_required(VERSION 3.16)
project(rpgCharGen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bf_chargen src/main.cpp)
