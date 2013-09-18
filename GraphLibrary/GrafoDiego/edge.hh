#include"dataStruc.hh"
#include <iostream>
#include <vector>


class Edge{

private:
	int v;
	int w;
	double weight;
	
public:

	Edge(int v, int w, double weight);
	double weight();
	int either();
	int other(int vertex);
	int compareTo(Edge that);
		
	
	

		

};

