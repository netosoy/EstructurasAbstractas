#include <iostream>
#include <vector>
#include <string>
#ifndef CLASEEDGE
#define CLASEEDGE
using namespace std;

class Edge{

private:
	int v;
	int w;
	float weight;
	
public:
	Edge();
	Edge(int v, int w, float weight);	
	float Weight();
	int either();
	int other(int vertex);
	int compareTo(Edge that);
	void toString();
	Edge& operator=(const Edge&);
	

};
#endif
