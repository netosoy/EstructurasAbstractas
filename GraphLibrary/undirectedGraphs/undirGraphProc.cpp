#include"undirGraphProc.hh"


DepthFirstSearch::DepthFirstSearch(Graph& G, int s){
  this->marked=new bool[G.V()];
  for(int i=0; i<G.V(); i++){
    marked[i]=false;
  }
  dfs(G,s);
}
DepthFirstSearch::~DepthFirstSearch(void){
  delete[] marked;
}
void DepthFirstSearch::dfs(Graph& G, int v){
  marked[v]=true;
  count++;
  MyBag* iterator= G.adjV(v);
  iterator->beginIte();
  int ite;
  while(iterator->hasNext())
    if(!marked[(ite=iterator->next())])
      dfs(G,ite);
}

//-------DFS to find paths, class implementation

DFSfindPaths::DFSfindPaths(Graph& G, int s){
  this->marked=new bool[G.V()];
  this->edgeTo=new int[G.V()];
  this->path=NULL;
  this->s=s;
  for(int i=0; i<G.V(); i++){
    marked[i]=false;
  }
  for(int i=0; i<G.V(); i++){
    edgeTo[i]=0;
  }
  dfs(G,s);
}
DFSfindPaths::~DFSfindPaths(void){
  delete[] marked;
  delete[] edgeTo;
  delete path;
}
void DFSfindPaths::dfs(Graph& G, int v){
  marked[v]=true;
  MyBag* iterator= G.adjV(v);
  iterator->beginIte();
  int ite;
  while(iterator->hasNext())
    if(!marked[(ite=iterator->next())]){
      edgeTo[ite]=v;
      dfs(G,ite);
    }
}
MyStack* DFSfindPaths::pathTo(int v){
  if(!hasPathTo(v))
    path=NULL;
  else{
    path=new MyStack();
    for(int x=v; x!=s; x=edgeTo[x])
      path->push(x);
    path->push(s);
  }
  return path;
}


//----Breadth first search for paths class implementation-----

BreadthFirstPaths::BreadthFirstPaths(Graph& G, int s){
  this->marked=new bool[G.V()];
  this->edgeTo=new int[G.V()];
  this->path=NULL;
  this->queue=NULL;
  this->s=s;
  for(int i=0; i<G.V(); i++){
    marked[i]=false;
  }
  for(int i=0; i<G.V(); i++){
    edgeTo[i]=0;
  }
  bfs(G,s);
}
BreadthFirstPaths::~BreadthFirstPaths(void){
  delete[] marked;
  delete[] edgeTo;
  delete path;
  delete queue;
}
void BreadthFirstPaths::bfs(Graph& G, int s){
  queue=new MyQueue();
  marked[s]=true;
  queue->enqueue(s);
  while(!queue->isEmpty()){
    int v=queue->dequeue();
    MyBag* iterator= G.adjV(v);
    iterator->beginIte();
    int ite;
    while(iterator->hasNext())
      if(!marked[(ite=iterator->next())]){
	edgeTo[ite]=v;
	marked[ite]=true;
	queue->enqueue(ite);
      }
  }
}
MyStack* BreadthFirstPaths::pathTo(int v){
  if(!hasPathTo(v))
    path=NULL;
  else{
    path=new MyStack();
    for(int x=v; x!=s; x=edgeTo[x])
      path->push(x);
    path->push(s);
  }
  return path;
}

//---DFS to find connected componentes class implementation---

CC::CC(Graph& G){
  this->marked=new bool[G.V()];
  this->id=new int[G.V()];
  this->count=0;
  for(int i=0; i<G.V(); i++){
    marked[i]=false;
  }
  for(int i=0; i<G.V(); i++){
    id[i]=0;
  }
}
CC::~CC(void){
  delete[] marked;
  delete[] id;
}
void CC::dfs(Graph& G, int v){
  marked[v]=true;
  id[v]=count;
  MyBag* iterator= G.adjV(v);
  iterator->beginIte();
  int ite;
  while(iterator->hasNext())
    if(!marked[(ite=iterator->next())]){
      dfs(G,ite);
    }
}
