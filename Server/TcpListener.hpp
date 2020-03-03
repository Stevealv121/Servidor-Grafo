//
// Created by steve on 24/02/20.
//

#ifndef SERVIDOR_GRAFO_TCPLISTENER_HPP
#define SERVIDOR_GRAFO_TCPLISTENER_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../Data Structures/Graph.hpp"

#define MAX_BUFFER_SIZE (4096)

/**
 * Forward declaration of class
 */

class TcpListener;

/**
 * callback to data received
 */
typedef void (*messageRecievedHandler)(TcpListener *listener,int socketId, std::string msg);

/**
 * Client class implementation
 */
class TcpListener {

public:

    TcpListener (std::string ipAddress, int port, messageRecievedHandler handler);
    ~TcpListener();

    /**
     * main processing loop
     */
    void run();

    /**
     * send a message to the specified client
     */
    void sendMessage(int clientSocket, std::string msg);

private:

    std::string m_ipAddress;
    int m_port;
    messageRecievedHandler messageReceived;

    //create socket
    int createSocket();


    /**
     * Wait for a connection
     * @param listening socket
     * @return client socket
     */
    int waitForConnection(int listening);

    /**
     * test dijkstra algorithm
     * @param clientSocket socket
     * @return test resolution
     */
    int runTest(int clientSocket);



};


#endif //SERVIDOR_GRAFO_TCPLISTENER_HPP
