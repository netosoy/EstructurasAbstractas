#include "EagerPrimMST.hh"

EagerPrimMST::EagerPrimMST(EdgeWeightedGraph &G){
	this->V=G.V();
	edgeTo = new Edge[V];
	distTo = new int[V];
	marked = new bool[V];
	for(int v=0; v < V; v++)
		distTo[v]=1000000;
	pq = new MinIndexedPQ(V);
	for(int i=0; i<=V;i++) marked[i]=false;
	
	distTo[0] = 0.0;
	pq->insert(0, 0.0);
	
	while(!pq->isEmpty()){
		visit(G, pq->deleteMin());}
}

EagerPrimMST::~EagerPrimMST(){

	delete [] edgeTo;
	delete [] distTo;
	delete [] marked;
	delete pq;

}

void EagerPrimMST::visit(EdgeWeightedGraph &G, int v){

	marked[v]=true;
	G.Iterator(v)->beginIterate();
	while (G.Iterator(v)->isEnd()){

		Edge e = G.Iterator(v)->getEdge();
		int w = e.other(v);

		if(marked[w]) continue;
		if(e.weight() < distTo[w]){
			edgeTo[w] = e;
			distTo[w] = e.weight();
			if(pq->contains(w)) 	{

			pq->decreaseKey(w, distTo[w]);
			}
		else						pq->insert(w, distTo[w]);	

		}
	}
}


void EagerPrimMST::printMST(){
	Edge * e = IterableMST();
	int cost = 0;
	for(int i = 1; i<V; i++){
		e[i].toString();
		cost += e[i].weight();
	}
	cout<<"El peso del MST es: "<<cost<<endl;
}

