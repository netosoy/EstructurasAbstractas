#include"kruskalMST.hh"

kruskalMST::kruskalMST(EdgeWeightedGraph &G){
	pq = G.priorityQueue();
	UnionFinder uf(G.V());
	while(!pq.empty()){
		Edge e = pq.top();// Get min weight edge on pq
		pq.pop();			
		int u = e.either(), v = e.other(u); // and its vertices.
		if(uf.connected(u,v)) continue;// Ignore ineligible edges.
		uf.Union(u,v);							// Merge components.
		mst.push(e);						// Add edge to mst.				
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
