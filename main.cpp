#include <iostream>
#include <string.h>
#include "TcpListener.hpp"
#include "Graph.hpp"
#include "Dijkstra.hpp"


using namespace std;

void ListenerMessageReceived(TcpListener *listener, int client, string msg);

int main(){

//    TcpListener server("127.0.0.1",54000,ListenerMessageReceived);
//    server.run();

    // graph edges array.
//    Graph::graphEdge edges[] = {
//
//            // (x, y, w) -> edge from x to y with weight w
//            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
//    };
//
//    int N = 6;      // Number of vertices in the graph
//    // calculate number of edges
//    int n = sizeof(edges)/sizeof(edges[0]);
//
//    // construct graph
//    Graph diagraph(edges, n, N);
//    // print adjacency list representation of graph
//    cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
//    for (int i = 0; i < N; i++)
//    {
//        // display adjacent vertices of vertex i
//        diagraph.printAdjList(diagraph.head[i], i);
//    }
    Dijkstra dijkstra;
    int graph[vertex][vertex]={{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
                               {0,0,0,0,1,0,0}};
    dijkstra.algorithm(graph,0);

    return 0;

}

void ListenerMessageReceived(TcpListener *listener, int client, string msg){

    listener->sendMessage(client,msg);


}