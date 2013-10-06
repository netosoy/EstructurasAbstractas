#include "DirWeightGraph.hh"
#include<iostream>
EdgeWeightedDigraph::EdgeWeightedDigraph(int v):adj(v){
    V = v;
	E = 0;
}

void EdgeWeightedDigraph::addEdge(int v, int w, double weight){
	DirectedEdge TempEdge(v,w,weight);
	adj[v].push_back(TempEdge);
	++E;
}

std::deque<DirectedEdge> *EdgeWeightedDigraph::Iterable(int v){
    return &adj[v];
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
    for(int i = 0; i<V;++i){
        adj[i].clear();
    }
//    delete []adj;
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

/*############################################################
 *####  Estructura para la deteccion de ciclos ###############
 *###########################################################*/
EdgeWeightedCycleFinder::EdgeWeightedCycleFinder(EdgeWeightedDigraph &G):
    edgeTo(G.GetV()),
    marked(G.GetV()),
    onStack(G.GetV())

{
    for(int i = 0; i<G.GetV();++i){
        onStack[i] = false;
        marked[i] = false;
    }
    for(int v = 0; v < G.GetV(); ++v)
        if (!marked[v])
            dfs(G,v);
}

void EdgeWeightedCycleFinder::dfs(EdgeWeightedDigraph &G, int v){
    onStack[v] = true;
    marked[v] = true;
    std::deque<DirectedEdge> *temp = G.Iterable(v);
    std::deque<DirectedEdge>::const_iterator it;
    for(it = temp->begin(); it != temp->end(); ++it){
        int w = it->to();
        if(hasCycle())
            return;
        else if(!marked[w]){
            edgeTo[w] = v;
            dfs(G,w);
        }
        else if(onStack[w]){
            for(int x = v; x != w; x = edgeTo[x])
                cycle.push_front(x);
            cycle.push_front(w);
            cycle.push_front(v);
        }
    }
    onStack[v] = false;
}
