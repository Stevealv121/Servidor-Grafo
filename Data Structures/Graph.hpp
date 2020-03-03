//
// Created by steve on 20/02/20.
//

#ifndef SERVIDOR_GRAFO_GRAFO_HPP
#define SERVIDOR_GRAFO_GRAFO_HPP


class Graph {

public:

    struct adjNode{
        int val, cost;
        adjNode* next;
    };


    adjNode* getAdjListNode(int value, int weight, adjNode* head);

    struct graphEdge{

        int start, end, weight;
    };

    adjNode **head;

    Graph(graphEdge edges[], int n, int N);
    ~Graph();
    void printAdjList(adjNode* ptr, int i);

private:

    int N; //number of nodes in the graph

};


#endif //SERVIDOR_GRAFO_GRAFO_HPP
