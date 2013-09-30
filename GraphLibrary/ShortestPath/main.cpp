#include "DirWeightGraph.hh"
#include<iostream>
#include"ShortestPath.hh"
int main()
{
    EdgeWeightedDigraph Prueba(4);
    Prueba.addEdge(0,1,2.5);
    Prueba.addEdge(1,2,3.2);
    Prueba.addEdge(2,3,0.5);
    Prueba.addEdge(3,0,2.8);
    Prueba.addEdge(0,2,1.2);
    Djikstra Prueba2(Prueba,0);
    std::cout<<Prueba2.GetdistTo(3)<<std::endl;
}
