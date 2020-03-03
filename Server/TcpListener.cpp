#include <utility>

//
// Created by steve on 24/02/20.
//

#include <iostream>
#include "TcpListener.hpp"
#include "../Algorithm/Dijkstra.hpp"
#include "../Data Structures/Graph.hpp"

TcpListener::TcpListener(std::string ipAddress, int port, messageRecievedHandler handler)
    :m_ipAddress(std::move(ipAddress)), m_port(port), messageReceived(handler)
{

}

TcpListener::~TcpListener() {

}

void TcpListener::run() {

    char buffer[MAX_BUFFER_SIZE];
    while(true)
    {
        //create a listening socket
        int listening = createSocket();
        if(listening == -1){
            break;
        }
        //wait for a connection
        int client = waitForConnection(listening);


        if(client != -1){
            close(listening);
            int bytesReceived = 0;
            do{


                memset(&buffer, 0, sizeof(buffer));

                bytesReceived = static_cast<int>(recv(client, buffer, MAX_BUFFER_SIZE, 0));
                if(bytesReceived>0){
                    if(messageReceived != nullptr){

                        //echo message
                        sendMessage(client,std::string(buffer, 0, static_cast<unsigned long>(bytesReceived)));

                        //sending test
                        runTest(client);

                    }

                }
            }while (bytesReceived>0);

            close(client);
        }

    }



}

void TcpListener::sendMessage(int clientSocket, std::string msg) {

    std::string endline = "\n";
    send(clientSocket,msg.c_str(),msg.size(), 0);
    send(clientSocket,endline.c_str(),endline.size(),0);

}


int TcpListener::createSocket() {

    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening != -1)
    {
        //bind ip Address and socket
        sockaddr_in hint{};
        hint.sin_family = AF_INET;
        hint.sin_port = htons(static_cast<uint16_t>(m_port));
        inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);
        int bindOk = bind(listening, (sockaddr*)&hint, sizeof(hint));
        if (bindOk != -1)
        {
            int listenOk = listen(listening, SOMAXCONN);
            if (listenOk == -1){
                return -1;
            }
        }
        else{

            return -1;
        }
    }

    std::cout<<"socket created"<<std::endl;


    return listening;
}

int TcpListener::waitForConnection(int listening) {

    int clientSocket = accept(listening, nullptr, nullptr);

    std::cout<<"connection established"<<std::endl;

    return clientSocket;
}

int TcpListener::runTest(int clientSocket) {

    std::cout<<"running test"<<std::endl;

    Dijkstra dijkstra;
    int graphD[vertex][vertex] = {{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},
                                  {2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
                                  {0,0,0,0,1,0,0}};
    dijkstra.algorithm(graphD,0);
    List list = dijkstra.getTestString();
    //list.display();

    //for loop, sending each line of the test to the client
    sendMessage(clientSocket,"Vertex\t\tDistance from source");
    for(int i=0; i<vertex; i++)
    {
        sendMessage(clientSocket,list.pop());
    }

    return 0;
}
