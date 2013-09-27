#include"weightedGraph.hh"


int main(void){
	//PRUEBA CLASE GRAPH:
	/*Graph mi_grafo;
	cout<<"Ingrese un vertice"<<endl;
	int Vertice;
	cin>>Vertice;
	cout<<"Los vertices conectados al vertice "<< Vertice<<" son: "<<endl;
	mi_grafo.print(Vertice);
	*/
	//PRUEBA CLASE EDGE:
	/*
	Edge arista(1,2,0.65);
	cout << arista.Weight() <<" "<< arista.either() <<" "<< arista.other(1) << endl; 
	arista.toString();
	MiBag bolsa;
	bolsa.add(arista);
	bolsa.iterate_Edge();*/
	//PRUEBA CLASE WEIGHTEDGRAPH
	EdgeWeightedGraph mi_grafo(5);
	Edge arista(1,2,0.65);
	Edge arista1(1,3,0.64);
	Edge arista2(4,2,0.70);
	Edge arista3(1,4,0.70);
	Edge arista4(3,2,0.70);
	Edge arista5(0,2,0.70);
	mi_grafo.addEdge(arista);
	mi_grafo.addEdge(arista1);
	mi_grafo.addEdge(arista2);
	mi_grafo.addEdge(arista3);
	mi_grafo.addEdge(arista4);
	mi_grafo.addEdge(arista5);
	int vertice;
	cin>>vertice;
	mi_grafo.Iterator(vertice)->beginIterate();
	cout<<mi_grafo.Iterator(vertice)->size_of()<<endl;

	while (mi_grafo.Iterator(vertice)->isEnd()){
		mi_grafo.Iterator(vertice)->getEdge().toString();
	}
	/*
	int Vertice;
	cin>>Vertice;
	cout<<"Los vertices conectados al vertice "<< Vertice<<" son: "<<endl;
	mi_grafo.Iterator(Vertice)->iterate_Edge();
	*/
	
	return 0;
}
