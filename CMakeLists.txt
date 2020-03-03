cmake_minimum_required(VERSION 3.12)
project(Servidor_Grafo)

set(CMAKE_CXX_STANDARD 14)


add_executable(Servidor_Grafo main.cpp "Data Structures/Graph.cpp" "Data Structures/Graph.hpp" Server/TcpListener.cpp Server/TcpListener.hpp Algorithm/Dijkstra.cpp Algorithm/Dijkstra.hpp "Data Structures/List.cpp" "Data Structures/List.hpp")