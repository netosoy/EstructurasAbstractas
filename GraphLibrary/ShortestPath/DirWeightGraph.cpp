#include "DirWeightGraph.hh"

EdgeWeightedDigraph::EdgeWeightedDigraph(int v){
    V = v;
	E = 0;
	adj = new std::deque<DirectedEdge>[v];
}

void EdgeWeightedDigraph::addEdge(int v, int w, double weight){
	DirectedEdge TempEdge(v,w,weight);
	adj[v].push_back(TempEdge);
	++E;
}

std::deque<DirectedEdge> *EdgeWeightedDigraph::Iterable(int v){
	return adj+v;
}

std::deque<DirectedEdge> *EdgeWeightedDigraph::edges(){
    TempPtr = new std::deque<DirectedEdge>();
    for(int v = 0; v < V; ++v){
        std::deque<DirectedEdge>::const_iterator it = adj[v].begin();
        while(it != adj[v].end())
            TempPtr->push_back(*it++);
    }
    return TempPtr;
}

EdgeWeightedDigraph::~EdgeWeightedDigraph(){
    delete []adj;
    //delete TempPtr;
}

/*################################################################*/
/*########################## Estructura de priority Queue #######*/
/*###############################################################*/

DijPQ::DijPQ(){}
DijPQ::~DijPQ(){}
int DijPQ::delMin(){
    IndexToWeight Temp = pq.front();
    pq.pop_front();
    std::make_heap(pq.begin(),pq.end(),Compare());
    return Temp.vertex;
}
bool DijPQ::contains(int v){
    IndexToWeight Temp(v,0.0);
    return std::find_if(pq.begin(),pq.end(),IndexToWeight(Temp)) != pq.end();
}
void DijPQ::change(int v, double weight){
    IndexToWeight Temp(v,weight);
    std::deque<IndexToWeight>::iterator it = std::find_if(pq.begin(),pq.end(),IndexToWeight(Temp));
    it->weight = weight;
    it->vertex = v;
    std::make_heap(pq.begin(),pq.end(),Compare());
}
void DijPQ::insert(int v, double weight){
    IndexToWeight Temp(v,weight);
    pq.push_back(Temp);
    std::make_heap(pq.begin(),pq.end(),Compare());
}

