//
// Created by steve on 29/02/20.
//

#ifndef SERVIDOR_GRAFO_DIJKSTRA_HPP
#define SERVIDOR_GRAFO_DIJKSTRA_HPP
#define vertex 7

#include <climits>
#include <iostream>


class Dijkstra {

public:

    int minimumDistance(int distance[], bool Dset[]);

    void algorithm(int graph[vertex][vertex], int src);

};


#endif //SERVIDOR_GRAFO_DIJKSTRA_HPP
