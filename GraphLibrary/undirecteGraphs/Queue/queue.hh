#include<iostream>
#include<string>
using namespace std;
#ifndef QUEUECLASS
#define QUEUECLASS

typedef struct node{
  int data;
  node *next;
} mynode;

class MyQueue{
private:
  mynode *first, *last;
  int queue_size;
public:
  MyQueue(void);
  ~MyQueue(void);
  bool pushBack(int);
  int pullFront(void);
  bool isEmpty(void);
  int getSize(void);
  void readQueue(void);
};
#endif
