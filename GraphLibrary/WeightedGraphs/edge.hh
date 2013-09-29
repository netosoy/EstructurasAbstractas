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
	int w;
	
public:
	Edge();
	Edge(int u, int v, int w);	
	int weight();
	int either();
	int other(int vertex);
	int compareTo(Edge that);
	void toString();
	Edge& operator=(const Edge&);
	

};
#endif
