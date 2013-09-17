#include"graph.hh"

int main(void){
	Graph mi_grafo;
	cout<<"Ingrese un vertice"<<endl;
	int Vertice;
	cin>>Vertice;
	cout<<"Los vertices conectados al vertice "<< Vertice<<" son: "<<endl;
	mi_grafo.print(Vertice);
	return 0;
}
