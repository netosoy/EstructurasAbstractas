#include <queue>
#include "weightedGraph.hh"
#include "unionFinder.hh"

using namespace std;

#ifndef CLASEKMST
#define CLASEKMST

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
