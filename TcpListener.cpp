//
// Created by steve on 24/02/20.
//

#include <iostream>
#include "TcpListener.hpp"

TcpListener::TcpListener(std::string ipAddress, int port, messageRecievedHandler handler)
    :m_ipAddress(ipAddress), m_port(port), messageReceived(handler)
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
            //TODO: close socket
            close(listening);
            int bytesReceived = 0;
            do{


                memset(&buffer, 0, sizeof(buffer));

                bytesReceived = recv(client,buffer,MAX_BUFFER_SIZE,0);
                if(bytesReceived>0){
                    if(messageReceived != NULL){

                        //messageReceived(this,client,std::string(buffer,0,bytesReceived));
                        sendMessage(client,std::string(buffer,0,bytesReceived));
                    }
                }
            }while (bytesReceived>0);

            close(client);
        }

    }



}

void TcpListener::sendMessage(int clientSocket, std::string msg) {

    send(clientSocket,msg.c_str(),msg.size()+1, 0);

}

void TcpListener::cleanup() {

}

int TcpListener::createSocket() {

    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening != -1)
    {
        //bind ip Address and socket
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(m_port);
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

        //sockaddr_in client;
        //socklen_t clientSize = sizeof(client);

    //int clientSocket = accept(listening, (sockaddr*)&client,&clientSize);

    int clientSocket = accept(listening, NULL,NULL);

    std::cout<<"connection stablished"<<std::endl;



    return clientSocket;
}
