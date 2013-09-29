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
		if (!marked[v]) visit(G, v);
		if (!marked[w]) visit(G, w);
	}
}

LazyPrimMST::~LazyPrimMST(){
	delete [] marked;
}

void LazyPrimMST::visit(EdgeWeightedGraph& G, int v){
	marked[v]=true;
	G.Iterator(v)->beginIterate();
	while (G.Iterator(v)->isEnd()){
		Edge e = G.Iterator(v)->getEdge();
		if(!marked[e.other(v)]){
			buf.push_back(e);
			pq.push(buf.back());
		}
	}
}

void LazyPrimMST::printMST(){
	queue<Edge> mst = IterableMST();
	while(!mst.empty()){
		Edge e = mst.front();
		e.toString();
		mst.pop();
	}

}

float LazyPrimMST::weight(){
	queue<Edge> mst= this->IterableMST();
	float w = 0;
	while(!mst.empty()){
		w += mst.front().weight();
		mst.pop();
	}
	return w;
}




