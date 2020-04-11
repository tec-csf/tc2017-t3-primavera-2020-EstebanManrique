// -*- lsst-c++ -*-

/*
 * This file is part of tc2017-t3-primavera-2020-EstebanManrique
 *
 * Developed for Algorithms Design and Analysis Class.
 * See the README file at the repository's root for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, 
 *
 * This program is distributed in the hope that it will help
 * this its creator to develop its coding habilities regarding algorithms design.
 */

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <time.h> 
#include <type_traits>

using namespace std;

/**
 * The implementation of the class Graph has the purpose of creating all the nodes
 * that will be part of this structure (the number is defined by the user), the connections
 * among all the nodes are also created (the number of connections inside the graph will be
 * random. as well as the nodes taken into consideration). 
 * 
 * Additionally, the method Coloring() wll give a color (in this case a number) avoiding the
 * repetition of these elements among interconnected nodes inside the graph.
 */
class Graph
{
    public:
    int graphIdentifier; //Number which is assigned when Node is Created; IT IS NOT THE ASSIGNED COLOR
    list <int> *adyacencyList; //Keeps the list of nodes to which each node is connnected to.

    Graph(int graphIdentifier) // Class Builder
    {
        this->graphIdentifier = graphIdentifier;
        adyacencyList = new list<int>[graphIdentifier];
    }

    /**
     * Creates a connection between 2 nodes
     * 
     * @param graph1, which represents one of the 2 nodes to be connected by this method.
     * @param graph2, which represents the second node to be connected by this method
     * 
     * @note This method is inside a loop in the main() function which allows a random number
     * of connections among nodes every time the program is compiled and run.
     */ 
    void addConnection(int graph1, int graph2)
    {
        adyacencyList[graph1].push_back(graph2);
        adyacencyList[graph2].push_back(graph1);
        cout<<"Nodo "<<graph1<<" conectado a nodo "<<graph2<<endl;
    }

    /**
     * Checks the list of adyacencu for each of the nodes conforming the Graph. Secondly,
     * it checks in a temporal vector what numbers have been assigned to the vectors with
     * connections to the one being colored. The color is assigned and then the vector is
     * restarted.
     * 
     * @note This method is performed over every single node of the graph.
     */
    void Coloring()
    {
        vector <int> nodesWithColor;
        nodesWithColor.push_back(0);

        for(int index = 1; index<graphIdentifier; index++)
        {
            nodesWithColor.push_back(-1);
        }

        vector <int> availableColors;

        for(int index = 0; index<graphIdentifier; index++)
        {
            availableColors.push_back(0); //0 for FALSE and 1 for TRUE
        }

        for(int index = 1; index<graphIdentifier; index++)
        {
           list<int>::iterator indexx;
           for(indexx = adyacencyList[index].begin(); indexx!=adyacencyList[index].end(); indexx++)
           {
               if(nodesWithColor.at(*indexx)!=(-1))
               {
                   availableColors.at(nodesWithColor.at(*indexx)) = 1;
               }
           }
           
           int index2;
           for(index2 = 0; index2<graphIdentifier; index2++)
           {
               if(availableColors.at(index2)==0)
               {
                   break;
               }
           }
           nodesWithColor.at(index) = index2;

           for(indexx = adyacencyList[index].begin(); indexx!=adyacencyList[index].end(); indexx++)
            {
               if(nodesWithColor.at(*indexx)!=(-1))
               {
                   availableColors.at(nodesWithColor.at(*indexx)) = 0;
               }
           }
        }
        for(int i = 0; i<graphIdentifier; i++)
        {
            cout << "Vertice " << i << ": numero "<<nodesWithColor.at(i) + 1<< endl;
        }
    }

};

/**
 * The user is asked to introduce the number of nodes that the graph will have.
 * Following this, random connections between all the nodes of the graph will begin
 * to be created with the method addConnection.
 * 
 * All the connections and the coloring is printed so the usr can see this information.
 */ 
int main()
{
    int graphNumber;
    cout<<"Introduce el número de nodos a ser introducidos en el grafo"<<endl;
    cin>>graphNumber;

    Graph gr(graphNumber);
    
    srand(time(NULL));
    
    for(int i = 0; i<(graphNumber+rand()%4); i++)
    {
        gr.addConnection(rand()%graphNumber, rand()%graphNumber);
    }
    gr.Coloring();
}
