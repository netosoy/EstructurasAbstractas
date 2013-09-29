#include"kruskalMST.hh"

kruskalMST::kruskalMST(EdgeWeightedGraph &G){
	pq = G.priorityQueue();
	UF uf(G.V());
	while(!pq.empty()){
		Edge e = pq.top();
		pq.pop();
		int u = e.either(), v = e.other(u);
		if(uf.connected(u,v)) continue;
		uf.Union(u,v);
		mst.push(e);
	}	
}

float kruskalMST::weight(){
	queue<Edge> mst= this->IterableMST();
	float w = 0;
	while(!mst.empty()){
		w += mst.front().weight();
		mst.pop();
	}
	return w;
}

void kruskalMST::printMST(){
	queue<Edge> mst = IterableMST();
	while(!mst.empty()){
		Edge e = mst.front();
		e.toString();
		mst.pop();
	}
}
