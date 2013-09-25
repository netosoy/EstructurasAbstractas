#include<string>
#include<iostream>
using namespace std;
#ifndef BAGCLASS
#define BAGCLASS

typedef struct node{
  int data;
  node* next;
} mynode;

class MyBag{
private:
  mynode* head;
  int bag_size;
public:
  MyBag(void);
  ~MyBag(void);
  void addData(int);
  bool isEmpty(void);
  int getSize(void);
  void readBag(void);
};
#endif
