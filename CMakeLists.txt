cmake_minimum_required(VERSION 3.12)
project(Servidor_Grafo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Servidor_Grafo main.cpp Grafo.cpp Grafo.hpp)