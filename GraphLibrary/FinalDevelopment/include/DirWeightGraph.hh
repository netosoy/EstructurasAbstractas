#ifndef DirectedEdge_H
#define DirectedEdge_H
class DirectedEdge{
public:
	DirectedEdge(int v_arg, int w_arg, double weight_arg):
	v(v_arg),
	w(w_arg),
	weight(weight_arg){}
    DirectedEdge():
    v(0),
    w(0),
    weight(0.0){
        v = 0;
        w = 0;
        weight = 0.0;
    }
    double Getweight() const {return weight;}
    int from() const {return v;}
    int to() const {return w;}
private:
	int v;
	int w;
	double weight;
};
#endif

#ifndef EdgeWeightedDigraph_H
#define EdgeWeightedDigraph_H
#include<deque>
#include<algorithm>
#include<functional>
class EdgeWeightedDigraph{
public:
	EdgeWeightedDigraph(int v);
	~EdgeWeightedDigraph();
    int GetV(){return V;}
    int GetE(){return E;}
	void addEdge(int v, int w,double weight);
	std::deque<DirectedEdge> *Iterable(int v);
    std::deque<DirectedEdge> *edges();
private:
    int V;
	int E;
    std::deque<DirectedEdge> *adj, *TempPtr;
};

struct IndexToWeight{
    IndexToWeight(int v,double w):
        vertex(v),
        weight(w)
    {}
    int vertex;
    double weight;
    bool operator()(const IndexToWeight &ItW) const {
        return vertex==ItW.vertex;
    }
};

struct Compare{
    bool operator()(const IndexToWeight &x, const IndexToWeight &y)
    {
        return x.weight > y.weight;
    }
};

class DijPQ{
public:
    DijPQ();
    ~DijPQ();
    bool isEmpty(){return pq.empty();}
    int delMin();
    bool contains(int v);
    void change(int v, double weight);
    void insert(int v, double weight);
    std::deque<IndexToWeight> *GetDeque(){
        return &pq;
    }
private:
    std::deque<IndexToWeight> pq;
};
#endif


#ifndef EDGEWEIGHTEDCYCLEFINDER_H
#define EDGEWEIGHTEDCYCLEFINDER_H
class EdgeWeightedCycleFinder
{
public:
    EdgeWeightedCycleFinder(EdgeWeightedDigraph &G);
    bool hasCycle(){return !cycle.empty();}
    std::deque<int> *GetCycle(){return &cycle;}
private:
    bool *marked;
    int *edgeTo;
    std::deque<int> cycle;
    bool *onStack;
    void dfs(EdgeWeightedDigraph &G, int v);
};

#endif // EDGEWEIGHTEDCYCLEFINDER_H
