#ifndef DirectedEdge_H
#define DirectedEdge_H
#include<vector>
/*!
 * \brief The DirectedEdge class
 *
 *This class is used for generating a directed edge, which is used as the container for the weight and direction of the edge.
 *
 */
class DirectedEdge{
public:
    /*!
     * \brief The constructor
     * \param v_arg The origin of the edge
     * \param w_arg The end of the edge
     * \param weight_arg The weight of the edge
     */
	DirectedEdge(int v_arg, int w_arg, double weight_arg):
	v(v_arg),
	w(w_arg),
	weight(weight_arg){}
    /*!
     * \brief Default constructor
     *
     *For use by the STL in order to generate empty containers of this class.
     */
    DirectedEdge():
    v(0),
    w(0),
    weight(0.0){
        v = 0;
        w = 0;
        weight = 0.0;
    }
    /*!
     * \brief Get Weight
     * \return  Returns the weight of the edge
     */
    double Getweight() const {return weight;}
    /*!
     * \brief From
     * \return Returns the source of the edge
     */
    int from() const {return v;}
    /*!
     * \brief to
     * \return Returns the destination of the edge
     */
    int to() const {return w;}
private:
    int v; /*!< Holds the source of the edge.*/
    int w; /*!< Holds the end of the edge.*/
    double weight; /*!< Holds the weight of the edge.*/
};
#endif

#ifndef EdgeWeightedDigraph_H
#define EdgeWeightedDigraph_H
#include<deque>
#include<algorithm>
#include<functional>
/*!
 * \brief The EdgeWeightedDigraph class
 *
 *Generates the adjacency list for the directed graph with weight.
 *
 */
class EdgeWeightedDigraph{
public:
    /*!
     * \brief Constructor
     * \param v The number of vertex the graph will store.
     */
	EdgeWeightedDigraph(int v);
    /*!
     *\brief Destructor
     */
	~EdgeWeightedDigraph();
    /*!
     * \brief Number of vertex
     * \return The number of vertex in the graph.
     */
    int GetV(){return V;}
    /*!
     * \brief Number of Edges
     * \return The number of edges in the graph.
     */
    int GetE(){return E;}
    /*!
     * \brief Add Edge
     * \param v the source of the new edge
     * \param w the end of the new edge
     * \param weight the weight of the new edge
     */
	void addEdge(int v, int w,double weight);
    /*!
     * \brief Iterable
     * \param v The vertex whose adjacency list will be iterated
     * \return A pointer to the deque that holds the adjacency list
     */
	std::deque<DirectedEdge> *Iterable(int v);
    /*!
     * \brief edges
     * \return A pointer to a deque that holds all the edges in the design
     */
    std::deque<DirectedEdge> *edges();
private:
    int V; /*! <The number of vertex in the graph*/
    int E; /*!< The number of edges in the graph*/
    std::deque<DirectedEdge> *TempPtr;
    std::vector< std::deque<DirectedEdge> > adj;/*!< The adjacency list*/
};

/*!
 * \brief The IndexToWeight struct
 *
 *Used by the priority queue to be able to sort the vertex based on the weight of the paths.
 */
struct IndexToWeight{
    /*!
     * \brief IndexToWeight
     * \param v The vertex that will be indexed.
     * \param w The weight of the indes to be indexed.
     */
    IndexToWeight(int v,double w):
        vertex(v),
        weight(w)
    {}
    int vertex; /*!< The vertex*/
    double weight;/*!< The weight*/
    /*!
     * \brief operator ()
     * \param ItW Paramenter to campare in order to find the right value.
     * \return Returns if the two Index to weight classes are equal.
     */
    bool operator()(const IndexToWeight &ItW) const {
        return vertex==ItW.vertex;
    }
};
/*!
 * \brief The Compare struct
 *
 *Used tho compare the values and order them using the heap STL algorithm
 */
struct Compare{
    bool operator()(const IndexToWeight &x, const IndexToWeight &y)
    {
        return x.weight > y.weight;
    }
};

/*!
 * \brief The DijPQ class
 *
 *This class holds the priority queue used for the Dijkstra algorithm.
 */
class DijPQ{
public:
    /*!
     * \brief Constructor
     */
    DijPQ();
    ~DijPQ();
    /*!
     * \brief isEmpty
     * \return A boolean value to endicate if the pq is empty.
     */
    bool isEmpty(){return pq.empty();}
    /*!
     * \brief delMin
     *
     *  Removes the smallest value in the pq.
     * \return The Index to Weight of the first value in the pq
     */
    int delMin();
    /*!
     * \brief contains
     *Check if the pq contains a given index.
     * \param v The index to look for.
     * \return A boolean that indicates if it the value is in the queue.
     */
    bool contains(int v);
    /*!
     * \brief change
     *Changes the weight of an index in the pq.
     * \param v The index whose weight must be changed
     * \param weight The new weight for the index
     */
    void change(int v, double weight);
    /*!
     * \brief insert
     *Inserts a new value in the priority queue
     * \param v The vertex that will be inserted
     * \param weight The weight of the vertex to be inserted.
     */
    void insert(int v, double weight);
    /*!
     * \brief GetDeque
     *Returns the address of the priority queue, so applications can access it.
     * \return The address to the priority queue
     */
    std::deque<IndexToWeight> *GetDeque(){
        return &pq;
    }
private:
    std::deque<IndexToWeight> pq; /*!< The deque that holds the priority queue*/
};
#endif


#ifndef EDGEWEIGHTEDCYCLEFINDER_H
#define EDGEWEIGHTEDCYCLEFINDER_H
/*!
 * \brief The EdgeWeightedCycleFinder class
 *
 *  This class allows the search of cycles inside the Bellman Ford structure
 */
class EdgeWeightedCycleFinder
{
public:
    /*!
     * \brief EdgeWeightedCycleFinder
     * \param G The graph to be analyzed
     */
    EdgeWeightedCycleFinder(EdgeWeightedDigraph &G);
    /*!
     * \brief hasCycle
     * \return A boolean that states if the graph has a cycle or not
     */
    bool hasCycle(){return !cycle.empty();}
    /*!
     * \brief GetCycle
     * \return An iterable deque that has the vertex that form the cycle.
     */
    std::deque<int> *GetCycle(){return &cycle;}
private:
    std::vector<int> edgeTo; /*!< A vector for storing the edges that connect the vertex*/
    std::vector<bool> marked,onStack;
    std::deque<int> cycle;/*!< The deque that holds the cycle*/
    /*!
     * \brief dfs
     *  This is an implementation of the depth first search algorithm that is used to look for the cycles.
     * \param G The graph that will be inspected for cycles
     * \param v The source.
     */
    void dfs(EdgeWeightedDigraph &G, int v);
};

#endif // EDGEWEIGHTEDCYCLEFINDER_H
