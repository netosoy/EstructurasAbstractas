#include "dataStruc.hh"
#include <iostream>
#include <vector>


class Graph{

private:
	int V; // numero de vertices
	int E; // numero de edges
	vector<MiBag> adj; // se crea el array de objetos MiBag
	MiBag * bolsa; // puntesro tipo MiBag

public:
	Graph(); // Lee el grafo en un archivo y lo representa en un lista de adyacencia
	~Graph();
	int Vertex(); // devuelve el numero de Vertices
	int Edges(); // devuelve el numero de edge
	void print(int s); // imprime los vertices adyacentes a s
	void addEdge(int v, int w); // agrega el edge conformado por los vertices v y w
};
