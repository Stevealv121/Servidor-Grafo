//
// Created by steve on 20/02/20.
//

#ifndef SERVIDOR_GRAFO_GRAFO_HPP
#define SERVIDOR_GRAFO_GRAFO_HPP

/**
 * Implementation of a graph structure using adjacency list
 */
class Graph {

public:
    /**
     * Node structure
     */
    struct adjNode{
        int val, cost;
        adjNode* next;
    };

    /**
     * Get adjacency list node
     * @param value of vertex
     * @param weight of edge
     * @param head node
     * @return adjacency list node
     */
    adjNode* getAdjListNode(int value, int weight, adjNode* head);
    /**
     * Edge structure
     */
    struct graphEdge{

        int start, end, weight;
    };

    adjNode **head;

    Graph(graphEdge edges[], int n, int N);
    ~Graph();
    /**
     * Print graph: edges representation
     * @param ptr node
     * @param i index
     */
    void printAdjList(adjNode* ptr, int i);

private:
/**
 * number of nodes in the graph
 */
    int N;

};


#endif //SERVIDOR_GRAFO_GRAFO_HPP
