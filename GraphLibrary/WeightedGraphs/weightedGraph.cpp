#include "weightedGraph.hh"
#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <sstream>

EdgeWeightedGraph::EdgeWeightedGraph(){
	
	
// Se leen las primeras dos lineas del archivo para obtener el valor de V (numero de vertices) y E (numero de edges):
	ifstream fin("tinyEW.txt");
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
	char line[255];
	for (int v=0; v<V; v++){
		bolsa = new MiBag;
		adj.push_back(*bolsa);
	}
	
	this->E=0;
	be>>this->E; // Se define el numero de edges

// El siguiente for lee el resto de lineas que representan los edges en el sig. formato: u v y w, donde v y u son los vertices que conforman el edge, y w el peso.
// primero se debe tomar cada linea, convertirla en string, dividir este en tres partes con la funcion split y convertirlas en int:
	int u,v;
	float w;
	for (int i = 0; i<E; i++){
		fin.getline(line,255);
		string s(line);
		vector <string> fields;
		boost::algorithm::split(fields, s, boost::algorithm::is_any_of(" "));
		istringstream bu(fields[0]);
		bu>>u;
		cout<<u<<" ";
		istringstream bv(fields[1]);
		bv>>v;
		cout<<v<<" ";
		istringstream bw(fields[2]);
		bw>>w;
		cout<<w<<" ";
		cout<<" "<<endl;
		Edge *e = new Edge(u,v,w);
		addEdge(e); // una vez obtenidos los dos vertices se utiliza el metodo addEdge para agregar el edge
	}	 
}

EdgeWeightedGraph::~EdgeWeightedGraph(){
	
}

int EdgeWeightedGraph::Vertex(){
	return V;
}

int EdgeWeightedGraph::Edges(){
	return E;
}

void EdgeWeightedGraph::addEdge(Edge* e){
	int u = e->either();
	int v = e->other(u);
	adj[u].add(*e); //agrega w a la lista de v
	adj[v].add(*e); // agrega v a la lista de w
}

void EdgeWeightedGraph::print(int V){
	adj[V].iterate_Edge(); // imprime los vertices conectados a el vertice V
}
