cmake_minimum_required(VERSION 3.10)

project(graph)

add_executable(graph Graph_Expression/Edge.h Graph_Expression/Node.h graph_basic_algorithm.cpp Graph_Expression/Graph.h)
