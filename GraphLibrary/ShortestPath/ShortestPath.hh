#ifndef DJIKSTRA_H
#define DJIKSTRA_H
#include"DirWeightGraph.hh"
#include<vector>
/*!
 * \brief The Djikstra class
 *  The implementation of the Djikstra algorithm for finding shortest path in a graph
 */
class Djikstra
{
public:
    /*!
     * \brief Djikstra
     * \param G The Graph that will be inspected
     * \param s The source of the spanning tree
     */
    Djikstra(EdgeWeightedDigraph &G,int s);
    /*!
     * \brief relax
     *  The core of the Djikstra algorithm, the vertex are inspected until the optimal path is found.
     * \param G The graph to be inspected
     * \param v The value that is next to be inspected
     */
    void relax(EdgeWeightedDigraph &G, int v);
    /*!
     * \brief GetdistTo
     *  Retrieves the weight of the path that connects the source to the vertex v.
     * \param v End vertex of the path
     * \return The weight of the path that connects the source to the vertex v.
     */
    double GetdistTo(int v){
        return distTo[v];
    }
    /*!
     * \brief hasPathTo
     *  Indicates is there is a path between the source and the vertex v.
     * \param v The end of the path.
     * \return A boolean that indicates if such a path exists.
     */
    bool hasPathTo(int v);
    /*!
     * \brief pathTo
     * \param v The vertex whose path is to be retrieved
     * \return An iterable that holds the edges that constitute the path.
     */
    std::deque<DirectedEdge> *pathTo(int v);
private:
    DirectedEdge *edgeTo; /*! Array that holds the edge that connect the vertex to the SP tree*/
    double *distTo; /*!< Array that holds the distance to every vertex*/
    DijPQ pq; /*!< Priority Queue for the Djikstra Algorithm*/
};

/*!
 * \brief The BellmanFord class
 *  The implementation of the BellmanFord algorithm for graph analysis.
 */
class BellmanFord{
public:
    /*!
     * \brief BellmanFord
     * \param G The graph to be processed
     * \param s The source of the SP tree
     */
    BellmanFord(EdgeWeightedDigraph &G, int s);
    /*!
     * \brief hasNegativeCycle
     * \return A boolean that indicates Negative Cycle is present
     */
    bool hasNegativeCycle();
    /*!
     * \brief pathTo
     *  Gives an iterable that contains the edges that form the path to vertex v
     * \param v Vertex whose path will be retrieved
     * \return An iterable or edges
     */
    std::deque<DirectedEdge> *pathTo(int v);
    /*!
     * \brief negativeCycle
     *
     * \return An iterable containing the vertex that form the negative cycle
     */
    std::deque<int> *negativeCycle();
    /*!
     * \brief hasPathTo
     * \param v The vertex that will be inspected for a path.
     * \return A boolean that indicates if there is a path from the source to the vertex v
     */
    bool hasPathTo(int v);
private:
    std::vector<double> distTo;/*!< A vector that contains the distance to all vertex*/
    std::vector<DirectedEdge> edgeTo;/*!< A vector that contains the edges connecting the vertex to the SP tree*/
    std::vector<bool> onQ;/*!< A vector that indicates the presence of vertex in the queue*/
    std::deque<int> queue, cycle;
    std::deque<DirectedEdge> path;/*!< Variable for temporarily storing the path to a given vertex*/
    int cost;/*!< cost of analysis*/
    /*!
     * \brief findNegativeCycle
     *   Function used for the detection of negative cycles inside the graph.
     */
    void findNegativeCycle();
    void relax(EdgeWeightedDigraph &G,int v);

};
#endif // DJIKSTRA_H11
