#ifndef DJIKSTRA_H
#define DJIKSTRA_H
#include"DirWeightGraph.hh"
#include<vector>
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
    double GetdistTo(int v);
    bool hasPathTo(int v);
    std::deque<DirectedEdge> *pathTo(int v);
    bool hasNegativeCycle();
    std::deque<int> *negativeCycle();
private:
    void relax(EdgeWeightedDigraph &G, int v);
    void findNegativeCycle();
    double *distTo;
    std::vector<DirectedEdge> edgeTo;
    bool *onQ;
    std::deque<int> queue;
    int cost, V;
    std::deque<int> cycle;
};
#endif // DJIKSTRA_H11
