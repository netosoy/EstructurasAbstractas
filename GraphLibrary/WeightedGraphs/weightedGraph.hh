#ifndef CLASEEWG
#define CLASEEWG

#include "Mybag.hh"
#include <iostream>
#include <vector>
#include <queue>


class CompareEdges{
public: 
	bool operator()(Edge& e1, Edge& e2){
		return (e1.compareTo(e2)==-1);
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
