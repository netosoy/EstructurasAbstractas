#ifndef CLASELPMST
#define CLASELPMST

#include "weightedGraph.hh"

using namespace std;


class LazyPrimMST{
private: 
	bool* marked; 
	queue<Edge> mst;
	vector<Edge> buf;
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;
	
	void visit(EdgeWeightedGraph& G, int v);
public:
	LazyPrimMST(EdgeWeightedGraph& G);
	~LazyPrimMST();
	float weight();
	queue<Edge> IterableMST(){
		return mst;
	}
	void printMST();
	
};
#endif

/*
int main(){
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;
	Edge u(1,2,2.36);
	Edge v(1,3,5.68);
	Edge t[2]={u,v};
	pq.push(t[0]);
	pq.push(t[1]);
		

	return 0;
}*/
