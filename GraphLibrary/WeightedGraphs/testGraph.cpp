#include"weightedGraph.hh"
#include"EagerPrimMST.hh"
#include"LazyPrimMST.hh"


#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <sstream>


int main(void){

	//PRUEBA CLASE EDGE:
	/*
	Edge arista(1,2,0.65);
	cout << arista.Weight() <<" "<< arista.either() <<" "<< arista.other(1) << endl; 
	arista.toString();
	MiBag bolsa;
	bolsa.add(arista);
	bolsa.iterate_Edge();*/
	
	/*
	//PRUEBA CLASE WEIGHTEDGRAPH
	EdgeWeightedGraph mi_grafo(5);
	Edge arista(1,2,0.65);
	Edge arista1(1,3,0.64);
	Edge arista2(4,2,0.70);
	Edge arista3(1,4,0.32);
	Edge arista4(3,0,0.3);
	Edge arista5(0,2,0.1);
	mi_grafo.addEdge(arista);
	mi_grafo.addEdge(arista1);
	mi_grafo.addEdge(arista2);
	mi_grafo.addEdge(arista3);
	mi_grafo.addEdge(arista4);
	mi_grafo.addEdge(arista5);

*/

// INICIO DE PRUEBA LAZY PRIM MST	
	int V,E;
	ifstream fin("tinyEW.txt");
	char vertex[255]; 
	char edges[255];
	fin.getline(vertex,255);//lee la primera linea
	fin.getline(edges,255);//lee la segunda linea
	string Ve(vertex); 
	string Ed(edges);
	istringstream bv(Ve);
	istringstream be(Ed);
	bv>>V;
	be>>E;
	char line[255];
	//MinIndexedPQ pq(E);//prueba
	EdgeWeightedGraph mi_grafo(V);
	
	int u,v;
	float w;
	for (int i = 0; i<E; i++){
		fin.getline(line,255);
		string s(line);
		vector <string> fields;
		boost::algorithm::split(fields, s, boost::algorithm::is_any_of(" "));
		istringstream bu(fields[0]);
		bu>>u;
		//cout<<u<<" ";
		istringstream bv(fields[1]);
		bv>>v;
		//cout<<v<<" ";
		istringstream bw(fields[2]);
		bw>>w;
		//cout<<w<<" ";
		//cout<<" "<<endl;
		Edge e(u,v,w);
		/*float u = e.weight();
		*/mi_grafo.addEdge(e);
	}
	
	
	//PRUEBA DE PRIORITY QUEUE QUE ALMACENA TODOS LOS EDGES:
	
	/*priority_queue<Edge, vector<Edge>, CompareEdges> pq = mi_grafo.priorityQueue(); 
	while(!pq.empty()){
		Edge e = pq.top();
		e.toString();
		pq.pop();
	}*/
	

	//EagerPrimMST l_mst(mi_grafo);
	cout<<"El MST es:"<<endl;
	LazyPrimMST l_mst(mi_grafo);
	l_mst.printMST();
	
	cout<<"El peso total del MST es: "<<l_mst.weight()<<endl;
	return 0;
}
