//
// Created by steve on 29/02/20.
//

#ifndef SERVIDOR_GRAFO_DIJKSTRA_HPP
#define SERVIDOR_GRAFO_DIJKSTRA_HPP
#define vertex 7

#include <climits>
#include <iostream>
#include "List.hpp"


class Dijkstra {

public:

    int minimumDistance(int distance[], bool Dset[]);

    void algorithm(int graph[vertex][vertex], int src);

    void sendTest(std::string *line);

    const List &getTestString() const;

    void setTestString(const List &testString);

    std::string msg;

private:

    List testString;

};


#endif //SERVIDOR_GRAFO_DIJKSTRA_HPP
