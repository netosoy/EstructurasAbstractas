#include "DirWeightGraph.hh"
#include<iostream>
#include"ShortestPath.hh"
int main()
{
    EdgeWeightedDigraph Prueba(8);
    Prueba.addEdge(4,5,0.35);
    Prueba.addEdge(5, 4, 0.35);
    Prueba.addEdge(4,7,0.37);
    Prueba.addEdge(5,7,0.28);
    Prueba.addEdge(7,5,0.28);
    Prueba.addEdge(5,1,0.32);
    Prueba.addEdge(0,4,0.38);
    Prueba.addEdge(0,2,0.26);
    Prueba.addEdge(7,3,0.39);
    Prueba.addEdge(1,3,0.29);
    Prueba.addEdge(2,7,0.34);
    Prueba.addEdge(6,2,1.20);
    Prueba.addEdge(3,6,0.52);
    Prueba.addEdge(6,0,1.40);
    Prueba.addEdge(6,4,1.25);
    Djikstra Prueba2(Prueba,0);
    std::deque<DirectedEdge> *tempP = Prueba2.pathTo(5);
    std::deque<DirectedEdge>::const_iterator it;
    for(it = tempP->begin(); it != tempP->end(); ++it)
        std::cout<<it->from()<<" "<<it->to()<<std::endl;
}
