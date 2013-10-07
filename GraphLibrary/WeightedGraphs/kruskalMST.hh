#ifndef CLASEKMST
#define CLASEKMST

#include <queue>
#include "weightedGraph.hh"
#include "unionFinder.hh"

using namespace std;

/*!
 * \brief Kruskal algorithm implementation
 
This implementation of Kruskal’s algorithm uses a queue to hold MST edges, a priority queue to hold edges not yet examined, and a union-find data structure for identifying ineligible edges. The MST edges are returned to the client in increasing order of their weights.
 */

class kruskalMST{
	queue<Edge> mst; /*!< MST vertices*/
	priority_queue<Edge, vector<Edge>, CompareEdges> pq; /*!< priority queu with all edges sorted by weight*/

public:
    /*!
     * \brief Constructor
     * \param G Analyzed weighted graph.
     */
	kruskalMST(EdgeWeightedGraph& G);
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
