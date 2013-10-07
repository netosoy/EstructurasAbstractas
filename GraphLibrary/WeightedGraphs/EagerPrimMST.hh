#ifndef CLASEEPMST
#define CLASEEPMST


#include "weightedGraph.hh"
#include "indexPriorityQ.cpp"
#include <climits>

using namespace std;
/*!
 * \brief The Eager implementation of Prim algorithm class
 *
 *This class is used for generating an MST using Prim's algorithm
 *This implementation of Prim’s algorithm keeps eligible crossing edges on an index priority queue.
 */


class EagerPrimMST{
private: 
	
	Edge* edgeTo;  /*!< Shortest edge from tree vertex*/
	float* distTo; /*!< dist[w]=edgeTo[w].weight()*/
	bool* marked;  /*!< True if v is on tree*/
	MinIndexedPQ* pq;  /*!< Eligible crossing edges*/
	int V;  /*!< Number of graph vertices*/
	
	 /*!
     * \brief Add v to the tree; update data structures
     * \param v The vertex that will be added.
     * \param G Weighted graph.
     */
	void visit(EdgeWeightedGraph& G, int v);
	public:
	/*!
     * \brief Constructor
     * \param G Analyzed weighted graph.
     */
	EagerPrimMST(EdgeWeightedGraph& G);
	/*!
     * \brief Destructor
    */
	~EagerPrimMST();
	/*!
     * \brief Gets MST total weight
     */
	float weight();
	    /*!
     * \brief Gets MST's edge queue
     */
	Edge* IterableMST(){
		return edgeTo;
	}
		    /*!
     * \brief Prints MST's edges
     */
	void printMST();
};
#endif

