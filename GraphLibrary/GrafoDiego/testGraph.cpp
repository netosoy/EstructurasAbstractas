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
	EdgeWeightedGraph mi_grafo;
		cout<<"Ingrese un vertice"<<endl;
	int Vertice;
	cin>>Vertice;
	cout<<"Los vertices conectados al vertice "<< Vertice<<" son: "<<endl;
	mi_grafo.print(Vertice);
	return 0;
}
