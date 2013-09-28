#include"LazyPrimMST.hh"


LazyPrimMST::LazyPrimMST(EdgeWeightedGraph& G){
	marked = new bool[G.V()];
	for(int i=0; i<=G.V();i++) marked[i]=false;
	visit(G,0);
	
	
	while(!pq.empty()){
		Edge e = pq.top();
		pq.pop();
		int v = e.either(), w = e.other(v);
		if (marked[v]&&marked[w]) continue;
		mst.push(e);
		e.toString();
		if (!marked[v]) visit(G, v);
		if (!marked[w]) visit(G, w);
	}
}


void LazyPrimMST::visit(EdgeWeightedGraph& G, int v){
	marked[v]=true;
	G.Iterator(v)->beginIterate();
	while (G.Iterator(v)->isEnd()){
		Edge e = G.Iterator(v)->getEdge();
		//e.toString();
		if(!marked[e.other(v)]){
			buf.push_back(e);
			pq.push(buf.back());
		}
	}
}




