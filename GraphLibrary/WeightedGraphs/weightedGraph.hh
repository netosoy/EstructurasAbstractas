#include "bag.hh"
#include <iostream>
#include <vector>
#include <queue>

#ifndef CLASEEWG
#define CLASEEWG

class CompareEdges{
public: 
	bool operator()(Edge& e1, Edge& e2){
		if(e1.compareTo(e2)==-1) return true;
		else return false;
	}
};

class EdgeWeightedGraph{

private:
	int NumV; // 
	int NumE; // 
	MyBag** adj; //
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;
	vector<Edge> buf; 
public:
	EdgeWeightedGraph(int V);
	~EdgeWeightedGraph();
	int V(); // 
	int E(); // 
	void print(int s); // 
	void addEdge( Edge ); //
	priority_queue<Edge, vector<Edge>, CompareEdges> priorityQueue(){
		return pq;
	}//return a priority queue with all the edges sorted by weight*/
	MyBag* Iterator(int v); //
};
#endif
