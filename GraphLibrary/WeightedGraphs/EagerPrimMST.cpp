#include "EagerPrimMST.hh"

EagerPrimMST::EagerPrimMST(EdgeWeightedGraph &G){

	edgeTo = new Edge[G.V()];
	distTo = new int[G.V()];
	marked = new bool[G.V()];

	for(int v=0; v < G.V(); v++)
		distTo[v]=1000000;
	pq = new MinIndexedPQ(G.V());
	for(int i=0; i<=G.V();i++) marked[i]=false;
	
	distTo[0] = 0.0;
	pq->insert(0, 0.0);
	
	while(!pq->isEmpty()){
		visit(G, pq->deleteMin());}
	//prueba:
	int cost=0;	
    for(int i=1; i<G.V(); i++)  {
        cost += distTo[i];
        cout<<i<<" "<<distTo[i]<<endl;
    }
    cout<<"Total cost of MST: "<<cost<<endl;
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

		if(marked[w]) {

		continue;}
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

