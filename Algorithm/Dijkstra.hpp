//
// Created by steve on 29/02/20.
//

#ifndef SERVIDOR_GRAFO_DIJKSTRA_HPP
#define SERVIDOR_GRAFO_DIJKSTRA_HPP
#define vertex 7

#include <climits>
#include <iostream>
#include "../Data Structures/List.hpp"

/**
 * Dijkstra Algorithm class
 */
class Dijkstra {

public:

    /**
     * set minimum distance between two vertices
     * @param distance between two defined vertex
     * @param Dset contains checked vertices
     * @return index counter
     */
    int minimumDistance(int distance[], bool Dset[]);

    /**
     * dijkstra algorithm implementation
     * @param graph to work with
     * @param src first element of the graph
     */
    void algorithm(int graph[vertex][vertex], int src);
    /**
     * String list to be send to the client
     * @return list of strings
     */
    const List &getTestString() const;
    /**
     * Set string list
     * @param testString resolution of dijkstra algorithm
     */
    void setTestString(const List &testString);




private:

    /**
     * Saves a list of the resolution of dijkstra algorithm
     */
    List testString;

};


#endif //SERVIDOR_GRAFO_DIJKSTRA_HPP
