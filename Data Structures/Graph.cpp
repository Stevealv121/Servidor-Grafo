//
// Created by steve on 20/02/20.
//

#include <iostream>
#include "Graph.hpp"

Graph::adjNode *Graph::getAdjListNode(int value, int weight, Graph::adjNode *head) {

    adjNode* newNode = new adjNode;
    newNode->val = value;
    newNode->cost = weight;

    newNode->next = head;   // point new node to current head
    return newNode;

}

Graph::Graph(Graph::graphEdge *edges, int n, int N) {

    // allocate new node
    head = new adjNode*[N]();
    this->N = N;
    // initialize head pointer for all vertices
    for (int i = 0; i < N; ++i)
        head[i] = nullptr;
    // construct directed graph by adding edges to it
    for (unsigned i = 0; i < n; i++)  {
        int start_ver = edges[i].start;
        int end_ver = edges[i].end;
        int weight = edges[i].weight;
        // insert in the beginning
        adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

        // point head pointer to new node
        head[start_ver] = newNode;
    }

}

Graph::~Graph() {

    for (int i = 0; i < N; i++) {
        delete[] head[i];
        delete[] head;
    }

}

void Graph::printAdjList(Graph::adjNode *ptr, int i) {

    while (ptr != nullptr) {

        std::cout << "(" << i << ", " << ptr->val<< ", " << ptr->cost << ") ";
        std::cout << std::endl;
        ptr = ptr->next;
    }

}
