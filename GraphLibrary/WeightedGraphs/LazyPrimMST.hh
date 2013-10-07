#ifndef CLASELPMST
#define CLASELPMST

#include "weightedGraph.hh"

using namespace std;
/*!
 * \brief The Lazy implementation of Prim algorithm class
 *
 *This class is used for generating an MST using Prim's algorithm
 *This implementation of Prim’s algorithm uses a priority queue to hold crossing edges, a vertex-in-dexed arrays to mark tree vertices, and a queue to hold MST edges. This implementation is a lazy approach where we leave ineligible edges in the priority queue.
 */

class LazyPrimMST{
private: 
	bool* marked; /*!< MST vertices*/
	queue<Edge> mst;/*!< MST edges*/
	vector<Edge> buf; /*!< priority queue auxiliary edge vector*/
	priority_queue<Edge, vector<Edge>, CompareEdges> pq; /*!< crossing and ineligibles edges*/
	    /*!
     * \brief Mark v and add to pq all edges from v to unmarked vertices
     * \param v The vertex that will be added.
     * \param G Weighted graph.
     */
	void visit(EdgeWeightedGraph& G, int v);
public:
	    /*!
     * \brief Constructor
     * \param G Analyzed weighted graph.
     */
	LazyPrimMST(EdgeWeightedGraph& G);
	    /*!
     * \brief Destructor
    */
	~LazyPrimMST();
	    /*!
     * \brief Gets MST total weight
     */
	float weight();
	    /*!
     * \brief Gets MST's edge queue
     */
	queue<Edge> IterableMST(){
		return mst;
	}
	    /*!
     * \brief Prints MST's edges
     */
	void printMST();
	
};
#endif

/*
int main(){
	priority_queue<Edge, vector<Edge>, CompareEdges> pq;
	Edge u(1,2,2.36);
	Edge v(1,3,5.68);
	Edge t[2]={u,v};
	pq.push(t[0]);
	pq.push(t[1]);
		

	return 0;
}*/
