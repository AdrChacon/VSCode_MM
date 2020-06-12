cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server main.cpp LinkedList.cpp LinkedList.h Node.cpp Node.h )