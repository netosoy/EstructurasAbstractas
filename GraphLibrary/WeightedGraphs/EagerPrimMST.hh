#include "weightedGraph.hh"
#include "indexPriorityQ.cpp"

using namespace std;

#ifndef CLASEEPMST
#define CLASEEPMST


class EagerPrimMST{
private: 
	
	Edge* edgeTo;
	float* distTo;
	bool* marked;
	MinIndexedPQ* pq;
	
	public:
	EagerPrimMST(EdgeWeightedGraph G);
	~EagerPrimMST();
	float weight();
	void visit(EdgeWeightedGraph G, int v);
	MinIndexedPQ* IterableMST(){
		return pq;
	}
	
};
#endif

