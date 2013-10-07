#ifndef CLASEEDGE
#define CLASEEDGE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Edge{

private:
	int u; //one vertex
	int v;	//the other vertex
	float w; //edge weight
	
public:
	Edge(); //default initializing constructor
	Edge(int u, int v, float w);	//initializing constructor
	float weight(); //weight of this edge
	int either(); //either of this edge's vertices
	int other(int vertex); //the othr vertex
	int compareTo(Edge e); //compare this edge weight to e
	void toString(); 	//Print edge nodes and weight
	Edge& operator=(const Edge&); //asignation overlad
	

};
#endif
