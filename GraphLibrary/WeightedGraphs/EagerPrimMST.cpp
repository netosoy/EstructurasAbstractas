#include "EagerPrimMST.hh"

EagerPrimMST::EagerPrimMST(EdgeWeightedGraph G){

	edgeTo = new Edge[G.V()];
	distTo = new float[G.V()];
	marked = new bool[G.V()];

	for(int v; v < G.V(); v++)
		distTo[v]=100000000.0;
	pq = new MinIndexedPQ(G.V());
	
	distTo[0] = 0.0;
	pq->insert(0, 0.0);
	
	while(!pq->isEmpty())
		visit(G, pq->deleteMin());
}

EagerPrimMST::~EagerPrimMST(){
	delete [] edgeTo;
	delete [] distTo;
	delete [] marked;
	delete pq;
	
}

void EagerPrimMST::visit(EdgeWeightedGraph G, int v){
	marked[v]=true;
	G.Iterator(v)->beginIterate();
	while (G.Iterator(v)->isEnd()){
		Edge e = G.Iterator(v)->getEdge();
		int w = e.other(v);
		if(marked[w]) continue;
		if(e.weight() < distTo[w]){
			edgeTo[w] = e;
			e.toString();
			distTo[w] = e.weight();
			if(pq->contains(w)) 	pq->changeKey(w, distTo[w]);
			else						pq->insert(w, distTo[w]);	
		}
	}
}

