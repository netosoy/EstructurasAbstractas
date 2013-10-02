#include"graph.hh"

//----------MyBag class implementation-----------

MyBag::MyBag(void){
  this->head=NULL;
  this->iterator=head;
  this->bag_size=0;
}
MyBag::~MyBag(void){
  Node* aux;
  while(head!=NULL){
    aux=head;
    head=aux->next;
    delete(aux);
    aux=NULL;
  }
  bag_size=0;
}
void MyBag::add(int item){
  Node* aux;
  aux = new Node;
  aux->addItem(item);
  aux->next=head;
  head=aux;
  bag_size++;
}
int MyBag::next(void){
  int item=iterator->getItem();
  iterator=iterator->next;
  return item;
}

//-------MyStack class implementation---------

MyStack::MyStack(void){
  this->head=NULL;
  this->iterator=head;
  this->stack_size=0;
}
MyStack::~MyStack(void){
  Node *aux;
  while(head!=NULL){
    aux=head;
    head=aux->next;
    delete(aux);
    aux=NULL;
  }
  stack_size=0;
}
bool MyStack::push(int item){
  Node *aux;
  aux = new Node;
  aux->addItem(item);
  aux->next=head;
  head=aux;
  stack_size++;
  return true;
}
int MyStack::pull(void){
  int item;
  Node *aux=head;  //to eliminate
  head=aux->next;
  item=aux->getItem();
  delete(aux);
  aux=NULL;
  stack_size--;
  return item;
}
int MyStack::next(void){
  int item=iterator->getItem();
  iterator=iterator->next;
  return item;
}

//--------MyQueue class implementation--------

MyQueue::MyQueue(void){
  this->head=NULL;
  this->last=NULL;
  this->iterator=head;
  this->queue_size=0;
}
MyQueue::~MyQueue(void){
  Node *aux;
  while(head!=NULL){
    aux=head;
    head=aux->next;
    if(head==NULL)
      last=head;   //head=last=NULL => queue is empty
    delete(aux);
    aux=NULL;
  }
  queue_size=0;
}

bool MyQueue::enqueue(int data){
  Node *aux;
  aux = new Node;
  if(head==NULL)
    head=aux;
  aux->addItem(data);
  aux->next=NULL;
  if(last!=NULL)
    last->next=aux;
  last=aux;
  queue_size++;
  return true;
}
int MyQueue::dequeue(void){
  int item;
  Node *aux=head;
  item=aux->getItem();
  head=aux->next;
  if(head==NULL)
    last=NULL;
  delete(aux);
  aux=NULL;
  queue_size--;
  return item;
}
int MyQueue::next(void){
  int item=iterator->getItem();
  iterator=iterator->next;
  return item;
}

//---------Graph class implementation-----------

Graph::Graph(int vertex){
  this->num_ver=vertex;
  this->num_edg=0;
  this->adj=new MyBag *[vertex];
  for(int i=0; i<vertex; ++i)
    adj[i] = new MyBag();
}
Graph::~Graph(void){
  delete[] adj;
}
int Graph::V(void){return num_ver;}
int Graph::E(void){return num_edg;}
void Graph::addEdge(int v, int w){
  //cout<<"adding "<<v<<"-"<<w<<" edge"<<endl;
  adj[v]->add(w);
  adj[w]->add(v);
  num_edg++;
}
MyBag* Graph::adjV(int vertex){return adj[vertex];}

//-------Search graph client implementation------

Search::Search(Graph* G, int s){
  this->graph = G;
  this->source=s;
}
Search::~Search(){}
bool Search::marked(int v){
  MyBag* iterator= graph->adjV(source);
  bool isConnected=false;
  iterator->beginIte();
  while(iterator->hasNext()){
    if(iterator->next()==v)
      isConnected=true;
  }
  return isConnected;
}
int Search::count(void){
  int n=0;
  for(int i=0; i<graph->V(); i++){
    if(marked(i))
      n++;
  }
  return n;
}

//-------Depth First Search class implementation-------

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
