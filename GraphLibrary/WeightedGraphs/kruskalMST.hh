#ifndef CLASEKMST
#define CLASEKMST

#include <queue>
#include "weightedGraph.hh"
#include "unionFinder.hh"

using namespace std;



class kruskalMST{
	queue<Edge> mst;
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;

	
public:
	kruskalMST(EdgeWeightedGraph& G);
	float weight();
	queue<Edge> IterableMST(){
		return mst;
	}
	void printMST();
	
	
};

#endif
