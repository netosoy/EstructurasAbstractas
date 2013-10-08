#include"undirGraph.hh"
using namespace std;

//----------------------------

#ifndef DFSCLASS
#define DFSCLASS

class DepthFirstSearch{
/*!
 * \brief The DepthFirstSearch class
 *
 *This class is used for travesing or searching graph data structure. It is a fundamental recursive method that follows the graph’s edges to find the vertices connected to the vertex provided as argument(or source vertex)

 */
private:
  bool* marked; /*!< marked vertices*/
  int count;/*!< vertices connected to the source*/
  void dfs(Graph&, int v);
public:
        /*!
         * \brief DepthFirstSearch
         * \param G undirected graph
         * \param s source vertex
         */
  DepthFirstSearch(Graph& G, int s);
         /*!
	  *brief Destructor
	  */
  ~DepthFirstSearch();
        /*!
         * \brief Marked To mark all of the vertices that are connected to the source vertex
         * \param w any graph vertex
         * \return
         */
  bool Marked(int w){return marked[w];};
        /*!
         * \brief Count 
         * \return the number of vertices connected to s
         */
  int Count(void){return count;};

};

#endif

//----------------------------

#ifndef DFSFINDPATHCLASS
#define DFSFINDPATHCLASS

class DFSfindPaths{
private:
  bool* marked;
  int* edgeTo;
  MyStack* path;
  int s;
  void dfs(Graph& G, int v);
public:
  DFSfindPaths(Graph& G, int s);
  ~DFSfindPaths();
  bool hasPathTo(int v){return marked[v];};
  MyStack* pathTo(int v);
};

#endif

//-----------------------

#ifndef BFPCLASS
#define BFPCLASS

class BreadthFirstPaths{
private:
  bool* marked;
  int* edgeTo;
  MyStack* path;
  MyQueue* queue;
  int s;
  void bfs(Graph& G, int s);
public:
  BreadthFirstPaths(Graph& G, int s );
  ~BreadthFirstPaths();
  bool hasPathTo(int v){return marked[v];};
  MyStack* pathTo(int v);
};

#endif

//-----------------------

#ifndef CC_CLASS
#define CC_CLASS

class CC{
private:
  bool* marked;
  int* id;
  int count;
  void dfs(Graph& G, int v);
public:
  CC(Graph& G);
  ~CC();
  bool connected(int v, int w){return id[v]==id[w];};
  int Id(int v){return id[v];};
  int Count(void){return count;};
};

#endif
