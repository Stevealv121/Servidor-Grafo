//
// Created by steve on 29/02/20.
//
#include <iostream>
#include "Dijkstra.hpp"
using namespace std;

int Dijkstra::minimumDistance(int *dist, bool *Dset) {

    int min = INT_MAX,index;
    for (int i=0;i<vertex;i++)
    {
        if(Dset[i]== false && dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void Dijkstra::algorithm(int graph[vertex][vertex], int src) {

    int distance[vertex];
    bool Dset[vertex];

    for(int i=0;i<vertex; i++){

        distance[i] = INT_MAX;
        Dset[i] = false;
    }

    distance[src] = 0;

    for(int i = 0; i<vertex; i++)
    {
        int m = minimumDistance(distance,Dset);
        Dset[m]=true;
        for(int i=0; i<vertex; i++){

            if(!Dset[i] && graph[m][i] && distance[m] != INT_MAX && distance[m]+graph[m][i]<distance[i])
                distance[i]=distance[m]+graph[m][i];
        }

    }

    cout<<"Vertex\t\tDistance from source"<<endl;
    List list;
    string catcher;
    string lol = "\t\t\t";
    for(int i = 0; i<vertex; i++)
    { //Printing

        char str=65+i; // Ascii values for pritning A,B,C..
        cout<<str<<lol<<distance[i]<<endl;
        catcher = str+lol+to_string(distance[i]);
        list.insert(catcher);
        //sendTest(&catcher);
        catcher = "";
    }
    setTestString(list);

}

void Dijkstra::sendTest(string *line ) {

    msg = *line;

}


const List &Dijkstra::getTestString() const {
    return testString;
}

void Dijkstra::setTestString(const List &testString) {

    Dijkstra::testString = testString;
}
