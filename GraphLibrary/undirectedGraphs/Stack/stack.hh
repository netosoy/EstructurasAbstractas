#include<string>
#include<iostream>
using namespace std;
#ifndef STACKCLASS
#define STACKCLASS

typedef struct node{
  int data;
  node *next;
} mynode;

class MyStack{
private:
  mynode *head;
  int stack_size;
public:
  MyStack(void);
  ~MyStack(void);
  bool push(int);
  int pull(void);
  bool isEmpty(void);
  int getSize(void);
  void readStack(void);
};
#endif
