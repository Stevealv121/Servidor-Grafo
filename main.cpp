#include <iostream>
#include <string.h>
#include "TcpListener.hpp"
#include "Graph.hpp"
#include "List.hpp"


using namespace std;

void ListenerMessageReceived(TcpListener *listener, int client, string msg);

int main(){

    TcpListener server("127.0.0.1",54000,ListenerMessageReceived);
    server.run();


    return 0;

}

void ListenerMessageReceived(TcpListener *listener, int client, string msg){

    listener->sendMessage(client,msg);


}