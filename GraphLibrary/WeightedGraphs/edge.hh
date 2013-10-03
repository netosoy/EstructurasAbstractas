#include <iostream>
#include <vector>
#include <string>
#ifndef CLASEEDGE
#define CLASEEDGE
using namespace std;

class Edge{

private:
	int u;
	int v;
	float w;
	
public:
	Edge();
	Edge(int u, int v, float w);	
	float weight();
	int either();
	int other(int vertex);
	int compareTo(Edge that);
	void toString();
	Edge& operator=(const Edge&);
	

};
#endif
