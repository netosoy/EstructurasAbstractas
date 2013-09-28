#include<string>
#include<iostream>
using namespace std;
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
  bool isEmpty(void);
  int getSize(void);
  void beginIte(void);
  bool hasNext(void);
  int next(void); 
};
#endif

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
  void adjV(int);
};
#endif
