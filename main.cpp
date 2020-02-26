#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "TcpListener.hpp"



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