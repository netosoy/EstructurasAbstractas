#include <string>
#include <iostream>
#include"edge.hh"

using namespace std;
#ifndef CLASEBAG
#define CLASEBAG

typedef struct S_celda{
	int data;
	Edge edge;
	S_celda *next;
} T_celda;

class MyBag{
private: 
	T_celda* first_element, * iterator;
	int N, position;
public: 
	MyBag(void);
	~MyBag(void);
	bool is_empty();
	void add(int);
	void add(const Edge&);
	void print_EdgeBag(void);
	int size_of(void);
	void beginIterate();
	Edge getEdge();
	bool isEnd();
	
};

#endif
