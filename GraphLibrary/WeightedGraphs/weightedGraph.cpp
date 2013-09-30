#include "weightedGraph.hh"

EdgeWeightedGraph::EdgeWeightedGraph(int V){

	this->NumV=V;
	this->NumE=0;
	adj = new MyBag*[V];
	for(int v = 0; v<V; v++){
		adj[v]= new MyBag();
	}
		 
}

EdgeWeightedGraph::~EdgeWeightedGraph(){

	delete adj;

}

int EdgeWeightedGraph::V(){
	return NumV;
}

int EdgeWeightedGraph::E(){
	return NumE;
}

void EdgeWeightedGraph::addEdge(Edge e){
	int u = e.either();
	int v = e.other(u);
	adj[u]->add(e); //
	adj[v]->add(e); //
	NumE++;
	buf.push_back(e);
	pq.push(buf.back());
}

MyBag* EdgeWeightedGraph::Iterator(int v){
	return adj[v];
}

void EdgeWeightedGraph::print(int V){
	adj[V]->print_EdgeBag(); // 
}

