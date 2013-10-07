#ifndef CLASEEWG
#define CLASEEWG

#include "Mybag.hh"
#include <iostream>
#include <vector>
#include <queue>

/*!
 * \brief Compare edges weights  
 *
 * Is needed by priority_queue, to sort Edge objects in a correct order
 *
 */
class CompareEdges{
public: 
    /*!
     * \brief Uses compareTo Edge member function to compare two edges weights 
     * \return True if e1s weight is lower than e2s 
     */
	bool operator()(Edge& e1, Edge& e2){
		return (e1.compareTo(e2)==-1);
	}
};
/*!
 * \brief Extension of graph adjacency list to edge weighted graphs
 *
 * Creates an adjacency list that contains in each node an edge bag where can be store all vertex inceident edges 
 *
 */
class EdgeWeightedGraph{

private:
	int NumV; /*!< Number of vertices*/
	int NumE; /*!< Number of edges*/  
	MyBag** adj; /*!< Double pointer to adjacency list matrix*/
	priority_queue<Edge, vector<Edge>, CompareEdges> pq; /*!< Priority queue where all edges will be stored*/
	vector<Edge> buf; 
public:
    /*!
     * \brief Constructor
     * \param V Number of graph vertices
     */
	EdgeWeightedGraph(int V);
	    /*!
     * \brief Destructor
     */
	~EdgeWeightedGraph();
	/*!
     * \brief Get number of vertices
     */
	int V(); 
	/*!
     * \brief Get number of edges
     */
	int E();
	/*!
     * \brief Prints all incident edges of v vertex
     */
	void print(int v);
	/*!
     * \brief Add edge e to this graph
     */
	void addEdge( Edge e);
	/*!
     * \brief Returns a priority queue with all the edges sorted by weight
     */	
	priority_queue<Edge, vector<Edge>, CompareEdges> priorityQueue(){
		return pq;
	}
		/*!
     * \brief Returns a bag structure pointer of the adjacency list
     */ 
	MyBag* Iterator(int v); //
};
#endif
