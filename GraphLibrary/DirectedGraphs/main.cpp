#include "Graph.h"
#include "DirGraphProc.h"
#include <iostream>
int main(){
	Graph G(3,Directed);
	G.addEdge(0, 1);
	G.addEdge(0,2);
	G.addEdge(2,1);
	DepthFirstOrder Connected(G);
	std::deque<int> *validation = Connected.GetreversePost();
	std::deque<int>::const_iterator prueba;
	for(prueba = validation->begin();prueba != validation->end(); ++prueba)
		std::cout << *prueba;

	std::cout<<std::endl;
}
