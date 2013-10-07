#include"undirGraph.hh"
using namespace std;

//----------------------------

#ifndef DFSCLASS
#define DFSCLASS

class DepthFirstSearch{
private:
  bool* marked;
  int count;
  void dfs(Graph&, int v);
public:
  DepthFirstSearch(Graph& G, int s);
  ~DepthFirstSearch();
  bool Marked(int w){return marked[w];};
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
  void dfs(Graph&, int v);
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
