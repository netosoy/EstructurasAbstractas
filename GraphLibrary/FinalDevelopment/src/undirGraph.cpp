#include"undirGraph.hh"

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
