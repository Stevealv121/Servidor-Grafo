#include <iostream>
#include <string.h>
#include "Server/TcpListener.hpp"
#include "Data Structures/Graph.hpp"


using namespace std;

void ListenerMessageReceived(TcpListener *listener, int client, string msg);

int main(){

    TcpListener server("127.0.0.1",54000,ListenerMessageReceived);
    server.run();

//    Graph::graphEdge edges[] = {{0,1,5},{0,2,3},{1,2,2},{1,4,3},{1,6,1},{2,3,7},{2,4,7}
//            ,{3,0,2},{2,5,6},{4,3,2},{4,5,1},{6,4,1}};
//    int vertices = 7;
//    int n_edges = sizeof(edges)/sizeof(edges[0]);
//
//    Graph graph(edges, n_edges, vertices);
//
//    std::cout<<"Graph adjacency list "<<std::endl<<"(start_vertex, end_vertex, weight):"<<std::endl;
//    for(int i = 0; i<vertices; i++){
//        graph.printAdjList(graph.head[i], i);
//    }


    return 0;

}

void ListenerMessageReceived(TcpListener *listener, int client, string msg){

    listener->sendMessage(client,msg);


}