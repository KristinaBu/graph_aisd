cmake_minimum_required(VERSION 3.27)
project(graph_aisd)

set(CMAKE_CXX_STANDARD 23)

add_executable(graph_aisd main.cpp
        Graphs/ListGraph.cpp
        Graphs/ListGraph.h
        Graphs/ArcGraph.cpp
        Graphs/ArcGraph.h
        Graphs/MatrixGraph.cpp
        Graphs/MatrixGraph.h
        Graphs/SetGraph.cpp
        Graphs/SetGraph.h
        Graphs/IGraph.h)
