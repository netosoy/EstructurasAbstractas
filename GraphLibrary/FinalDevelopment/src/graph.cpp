#include "graph.hh"
#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <sstream>

Graph::Graph(){
	
	
// Se leen las primeras dos lineas del archivo para obtener el valor de V (numero de vertices) y E (numero de edges):
	ifstream fin("tiny.txt");
	char line[255];
	char vertex[255]; 
	char edges[255];
	fin.getline(vertex,255);//lee la primera linea
	fin.getline(edges,255);//lee la segunda linea
	string Ve(vertex);
	string Ed(edges);
	istringstream bv(Ve);
	istringstream be(Ed);
// Se obtienen a traves de streams de strings que se redirigen a un dato tipo int: 
	bv>>this->V;
	
// Una vez obtenido el valor del numero de vertices, se crean V objetos tipo bags y se insertan el el array que representa la lista de adyacencia
// con el siguiente for:
	
	for (int v=0; v<V; v++){
		bolsa = new MiBag;
		adj.push_back(*bolsa);
	}
	
	this->E=0;
	be>>this->E; // Se define el numero de edges

// El siguiente for lee el resto de lineas que representan los edges en el sig. formato: w v, donde w y v son los vertices que conforman el edge,
// primero se debe tomar cada linea, convertirla en string, dividir este en dos partes con la funcion split y convertirlas en int:
	int w,v;
	for (int i = 0; i<E; i++){
		fin.getline(line,255);
		string s(line);
		vector <string> fields;
		boost::algorithm::split(fields, s, boost::algorithm::is_any_of(" "));
		istringstream bw(fields[0]);
		bw>>w;
		cout<<w<<" ";
		istringstream bv(fields[1]);
		bv>>v;
		cout<<v<<" ";
		cout<<" "<<endl;
		addEdge(w, v); // una vez obtenidos los dos vertices se utiliza el metodo addEdge para agregar el edge
	}	 
}

Graph::~Graph(){
	
}

int Graph::Vertex(){
	return V;
}

int Graph::Edges(){
	return E;
}

void Graph::addEdge(int v, int w){
	adj[v].add(w); //agrega w a la lista de v
	adj[w].add(v); // agrega v a la lista de w
}

void Graph::print(int V){
	adj[V].iterate_Int(); // imprime los vertices conectados a el vertice V
}
