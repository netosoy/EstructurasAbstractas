#include "ShortestPath.hh"
#include<math.h>
Djikstra::Djikstra(EdgeWeightedDigraph &G,int s){
    edgeTo = new DirectedEdge[G.GetV()];
    distTo = new double(G.GetV());
    for(int v = 0; v<G.GetV();++v)
        distTo[v] = INFINITY;
    distTo[s]=0.0;

    pq.insert(s,0.0);
    while(!pq.isEmpty())
        relax(G, pq.delMin());

}
void Djikstra::relax(EdgeWeightedDigraph &G, int v){
    std::deque<DirectedEdge> *temp = G.Iterable(v);
    std::deque<DirectedEdge>::const_iterator it;
    for(it = temp->begin();it != temp->end(); ++it){
        int w = it->to();
        if(distTo[w] > distTo[v] + it->Getweight()){
            distTo[w] =distTo[v] + it->Getweight();
            edgeTo[w] = *it;
            if(pq.contains(w))
                pq.change(w,distTo[w]);
            else
                pq.insert(w,distTo[w]);
        }
    }
}
bool Djikstra::hasPathTo(int v){
    return distTo[v] < INFINITY;
}

std::deque<DirectedEdge> *Djikstra::pathTo(int v){
    if(!hasPathTo(v))
         return 0;
    std::deque<DirectedEdge> *path =  new std::deque<DirectedEdge>();
    for(DirectedEdge e = edgeTo[v]; e.from() || e.to() || e.Getweight(); e =edgeTo[e.from()])
        path->push_front(e);
    return path;
}

/*#########################################################
 *##########################Bellman Ford Definition########
 *########################################################*/

BellmanFord::BellmanFord(EdgeWeightedDigraph &G, int s){
    distTo = new double(G.GetV());
    size = G.GetV();
    edgeTo = new DirectedEdge[G.GetV()];
    onQ = new bool(G.GetV());
    for(int v = 0; v<G.GetV();++v)
        distTo[v] = INFINITY;
    distTo[s]= 0.0;
    queue.push_back(s);
    onQ[s]=true;
    while(!queue.empty()&& !hasNegativeCycle()){
        int v = queue.front();
        queue.pop_front();
        onQ[v] = false;
        relax(G,v);
    }
}

void BellmanFord::relax(EdgeWeightedDigraph &G, int v){
    std::deque<DirectedEdge> *temp = G.Iterable(v);
    std::deque<DirectedEdge>::const_iterator it;
    for(it = temp->begin();it != temp->end(); ++it){
        int w = it->to();
        if(distTo[w] > distTo[v] + it->Getweight()){
            distTo[w] = distTo[v] + it->Getweight();
            edgeTo[w] = *it;
            if (!onQ[w]){
                queue.push_back(w);
                onQ[w] = true;
            }
        }
        if(cost++ % G.GetV() == 0)
            findNegativeCycle();
    }
}

bool BellmanFord::hasNegativeCycle(){
    return !cycle.empty();
}
std::deque<DirectedEdge> *BellmanFord::negativeCycle(){
    int V = size;
    EdgeWeightedDigraph spt(V);
    for(int v = 0; v<V; ++v)
        if(edgeTo[v].Getweight() || edgeTo[v].to() || edgeTo[v].from())
            spt.addEdge(edgeTo[v].from(),edgeTo[v].to(),edgeTo[v].Getweight());
}
void BellmanFord::findNegativeCycle(){}
