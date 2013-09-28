#include"graph.hh"

//----------MyBag class implementation-----------

MyBag::MyBag(void){
  this->head=NULL;
  this->iterator=head;
  this->bag_size=0;
}
MyBag::~MyBag(void){
  cout<<"clearing the bag"<<endl;
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
bool MyBag::isEmpty(void){return head == NULL;
}
int MyBag::getSize(void){return bag_size;
}
void MyBag::beginIte(void){iterator=head;
}
bool MyBag::hasNext(void){return iterator!=NULL;
}
int MyBag::next(void){
  int item=iterator->getItem();
  iterator=iterator->next;
  return item;
}

//---------Graph class implementation-----------

Graph::Graph(int vertex){
  //cout<<"creating a graph of "<<vertex<<" vertices"<<endl;
  this->num_ver=vertex;
  this->num_edg=0;
  this->adj=new MyBag *[vertex];
  for(int i=0; i<vertex; ++i)
    adj[i] = new MyBag();
}
Graph::~Graph(void){
  delete adj;
}
int Graph::V(void){return num_ver;}
int Graph::E(void){return num_edg;}
void Graph::addEdge(int v, int w){
  //cout<<"adding "<<v<<"-"<<w<<" edge"<<endl;
  adj[v]->add(w);
  adj[w]->add(v);
  num_edg++;
}
void Graph::adjV(int vertex){
  //cout<<"adjacents vertices to "<<vertex<<" vertice"<<endl;
  adj[vertex]->beginIte();
  while(adj[vertex]->hasNext()){
    cout<<adj[vertex]->next()<<", ";
  }
  cout<<endl;
}
