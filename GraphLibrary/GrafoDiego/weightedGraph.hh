#include "dataStruc.hh"
#include <iostream>
#include <vector>


class EdgeWeightedGraph{

private:
	int V; // numero de vertices
	int E; // numero de edges
	vector<MiBag> adj; // se crea el array de objetos MiBag
	MiBag * bolsa; // punteros tipo MiBag

public:
	EdgeWeightedGraph(); // Lee el grafo en un archivo y lo representa en un lista de adyacencia
	~EdgeWeightedGraph();
	int Vertex(); // devuelve el numero de Vertices
	int Edges(); // devuelve el numero de edge
	void print(int s); // imprime los vertices adyacentes a s
	void addEdge( Edge* ); // agrega el objeto edge
};
