#ifndef CLASEEDGE
#define CLASEEDGE

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*! \brief Edge class representation

An edge can be represented as a simple structure that contains the two nodes
that it joins, and its weight. Also this class allows to compare two edges weights.
*/
class Edge{

private:
	int u;  /*!< One vertex*/
	int v;	/*!< The other vertex*/
	float w; /*!< Edge weight*/
	
public:
  /*!
     * \brief Constructor of an empty edge
     */
	Edge();
	  /*!
     * \brief Initializing constructor
     * \param u one vertex
     * \param v the other vertex
     * \param w Edge weight
     */
	Edge(int u, int v, float w);
	    /*!
     * \brief Returns the edge weight
     */
	float weight();
	  /*!
     * \brief Returns either of this edge's vertices
     */
	int either(); 
		  /*!
     * \brief Returns the other vertex
      \param vertex One of this edge vertices
     */
	int other(int vertex);
			  /*!
     * \brief Compare this edge weight to e's weight
      \param e Other edge 
     */
	int compareTo(Edge e); 
		  /*!
     * \brief Print edge's nodes and weight
     */
	void toString();
	 /*!
     * \brief Asignation operator overload
     */
	Edge& operator=(const Edge&); 
	

};
#endif
