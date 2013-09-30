#ifndef DJIKSTRA_H
#define DJIKSTRA_H
#include"DirWeightGraph.hh"
class Djikstra
{
public:
    Djikstra(EdgeWeightedDigraph &G,int s);
    void relax(EdgeWeightedDigraph &G, int v);
    double GetdistTo(int v){
        return distTo[v];
    }
    bool hasPathTo(int v);
    std::deque<DirectedEdge> *pathTo(int v);
private:
    DirectedEdge *edgeTo;
    double *distTo;
    DijPQ pq;
};

class BellmanFord{
public:
    BellmanFord(EdgeWeightedDigraph &G, int s);
    bool hasNegativeCycle();
    std::deque<DirectedEdge> *negativeCycle();

private:
    double *distTo;
    DirectedEdge *edgeTo;
    bool *onQ;
    std::deque<int> queue;
    int cost;
    std::deque<DirectedEdge> cycle;
    void relax(EdgeWeightedDigraph &G, int v);
    void findNegativeCycle();
    int size;
};
#endif // DJIKSTRA_H11
