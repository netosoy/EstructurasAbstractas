#include <string>
#include <iostream>
#include"edge.hh"

using namespace std;
#ifndef CLASEESTRUCTURAS
#define CLASEESTRUCTURAS

typedef struct S_celda{
	int dato;
	Edge edge;
	S_celda *proximo;
} T_celda;

class MiPila {
private: 
	T_celda *primer_elemento;
	int N;
public:
	MiPila(void);
	~MiPila(void);
	bool is_empty();
	void push(int);
	int pull(void);
	int size_of(void);	
	void iterate(void);		
};

class MiQueue {
private: 
	T_celda *primer_elemento, *ultimo_elemento;
	int N;
public:
	MiQueue(void);
	~MiQueue(void){}
	bool is_empty();
	void enqueue(int);
	int dequeue(void);
	int size_of(void);
	void iterate(void);	
};

class MiBag {
private: 
	T_celda *primer_elemento;
	int N;
public: 
	MiBag(void);
	~MiBag(void);
	bool is_empty();
	void add(int);
	void add(const Edge&);
	void iterate_Int(void);
	void iterate_Edge(void);
	int size_of(void);
};

class DeQueue {
private: 
	T_celda *primer_elemento, *ultimo_elemento;
	int N;
public:
	DeQueue(void);
	~DeQueue(void){}
	bool is_empty();
	void pushLeft(int);
	void pushRight(int);
	int popLeft(void);
	int popRight(void);
	int size_of(void);
	void iterate(void);	
};
#endif
