cmake_minimum_required(VERSION 2.8.9)

project (graph)

include_directories(include)

add_executable(
    graph
    src/main.cpp
    src/Graph.cpp
)