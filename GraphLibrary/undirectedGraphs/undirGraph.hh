#include<string>
#include<iostream>
using namespace std;

//----------------------------

#ifndef NODECLASS
#define NODECLASS

class Node{
private:
  int item;
public:
  Node(){item=0; next=NULL;};
  ~Node(){};
  void addItem(int data){item=data;};
  int getItem(void){return item;};
  Node *next;
  };
#endif

//----------------------------

#ifndef BAGCLASS
#define BAGCLASS

class MyBag{
private:
  Node *head, *iterator;
  int bag_size;
public:
  MyBag(void);
  ~MyBag(void);
  void add(int);
  bool isEmpty(void){return head==NULL;};
  int getSize(void){return bag_size;};
  void beginIte(void){iterator=head;};
  bool hasNext(void){return iterator!=NULL;};
  int next(void); 
};
#endif

//----------------------------

#ifndef STACKCLASS
#define STACKCLASS

class MyStack{
private:
  Node *head, *iterator;
  int stack_size;
public:
  MyStack(void);
  ~MyStack(void);
  bool push(int);
  int pull(void);
  bool isEmpty(void){return head==NULL;};
  int getSize(void){return stack_size;};
  void beginIte(void){iterator=head;};
  bool hasNext(void){return iterator!=NULL;};
  int next(void); 
};
#endif

//----------------------------

#ifndef QUEUECLASS
#define QUEUECLASS

class MyQueue{
private:
  Node *head, *last, *iterator;
  int queue_size;
public:
  MyQueue(void);
  ~MyQueue(void);
  bool enqueue(int);
  int dequeue(void);
  bool isEmpty(void){return head==NULL;};
  int getSize(void){return queue_size;};
  void beginIte(void){iterator=head;};
  bool hasNext(void){return iterator!=NULL;};
  int next(void); 
};

#endif
//----------------------------

#ifndef GRAPHCLASS
#define GRAPHCLASS

class Graph{
private:
  int num_edg, num_ver;
  MyBag** adj;
public:
  Graph(int);
  ~Graph(void);
  int V(void);
  int E(void);
  void addEdge(int, int);
  MyBag* adjV(int);
};
#endif
