#include <queue>
#include "weightedGraph.hh"

using namespace std;

#ifndef CLASELPMST
#define CLASELPMST

class CompareEdges{
public: 
	bool operator()(Edge& e1, Edge& e2){
		if(e1.compareTo(e2)==1) return true;
		else return false;
	}
};

class LazyPrimMST{
private: 
	bool* marked; 
	queue<Edge> mst;
	vector<Edge> buf;
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;
	
	void visit(EdgeWeightedGraph& G, int v);
public:
	LazyPrimMST(EdgeWeightedGraph& G);
	queue<Edge> IterableMST(){
		return mst;
	}

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
