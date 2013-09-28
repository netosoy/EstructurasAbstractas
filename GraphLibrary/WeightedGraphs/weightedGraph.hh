#include "bag.hh"
#include <iostream>
#include <vector>
#ifndef CLASEEWG
#define CLASEEWG

class EdgeWeightedGraph{

public:
	int NumV; // 
	int NumE; // 
	MyBag** adj; // 

	EdgeWeightedGraph(int V);
	~EdgeWeightedGraph();
	int V(); // 
	int E(); // 
	void print(int s); // 
	void addEdge( Edge ); //
	MyBag* Iterator(int v); //
};
#endif
