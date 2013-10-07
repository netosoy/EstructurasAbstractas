#ifndef CLASEEPMST
#define CLASEEPMST


#include "weightedGraph.hh"
#include "indexPriorityQ.cpp"
#include <climits>

using namespace std;



class EagerPrimMST{
private: 
	
	Edge* edgeTo;
	float* distTo;
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

