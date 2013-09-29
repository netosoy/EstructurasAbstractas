#include "weightedGraph.hh"
#include "indexPriorityQ.cpp"
#include <climits>

using namespace std;

#ifndef CLASEEPMST
#define CLASEEPMST


class EagerPrimMST{
private: 
	
	Edge* edgeTo;
	int* distTo;
	bool* marked;
	MinIndexedPQ* pq;
	int V;
	
	public:
	EagerPrimMST(EdgeWeightedGraph& G);
	~EagerPrimMST();
	float weight();
	void visit(EdgeWeightedGraph& G, int v);
	Edge* IterableMST(){
		return edgeTo;
	}
	void printMST();
};
#endif

