#include"LazyPrimMST.hh"


LazyPrimMST::LazyPrimMST(EdgeWeightedGraph G){
	marked = new bool[G.V()];
	
}


void LazyPrimMST::visit(EdgeWeightedGraph G, int v){
	marked[v]=true;
	while (G.Iterator(v)->isEnd()){
		if(!marked[G.Iterator(v)->getEdge().other(v)]){
			buf.push_back(G.Iterator(v)->getEdge());
			pq.push(buf.back());
		}
	}
}



