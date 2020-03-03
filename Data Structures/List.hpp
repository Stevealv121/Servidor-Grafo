//
// Created by steve on 02/03/20.
//

#ifndef SERVIDOR_GRAFO_LIST_HPP
#define SERVIDOR_GRAFO_LIST_HPP

#include <iostream>


class List {
public:

    struct node
    {
        std::string data;
        node *next;
    };
    List();

    void createnode(std::string value);
    void display();
    void insert(std::string value);

    std::string pop();

private:


    node *head, *tail;

};


#endif //SERVIDOR_GRAFO_LIST_HPP
