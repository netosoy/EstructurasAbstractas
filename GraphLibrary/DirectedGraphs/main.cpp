#include "Graph.h"
#include "DirGraphProc.h"
#include <iostream>
int main(){
	Graph G(3,Directed);
	G.addEdge(0, 1);
	G.addEdge(0,2);
	G.addEdge(1,2);
//	G.addEdge(2,1);
	DirectedDFS Connected(G, 1);
	if(Connected.Reachable(2)){
		std::cout<<"Puede Que funcione"<<std::endl;
	}	
	Bag *bagPrueba;
	for(int i = 0; i < 3; ++i){
		bagPrueba = G.Iterator(i);
		bagPrueba->BeginIter();
		while(bagPrueba->HasNext())
			std::cout<<bagPrueba->Next();
		std::cout<<std::endl;
	}
}
