cmake_minimum_required(VERSION 3.8)
project(p02___Domino_Art)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

set(SOURCE_FILES main.cpp)
add_executable(p02___Domino_Art ${SOURCE_FILES})