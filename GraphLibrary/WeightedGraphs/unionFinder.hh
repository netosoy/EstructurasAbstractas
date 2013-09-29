#include <iostream>
#ifndef CLASEUF
#define CLASEUF
using namespace std;
class UF{
	
	int* id; 
	int count, size;
	
public:

	UF(int N); //initialize N sites wirh integer names (0 to N-1)
	~UF();
	void Union(int p, int q); // add connection between p and q
	int find(int p); // component identifier for p(0 to N-1)
	bool connected(int p, int q); // return true if p and are in the same component
	int Count(void); // number of components
	 

};

#endif
