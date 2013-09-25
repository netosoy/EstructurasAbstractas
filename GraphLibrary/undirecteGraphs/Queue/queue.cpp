#include"queue.hh"

MyQueue::MyQueue(void){
  this->first=NULL;
  this->last=NULL;
  this->queue_size=0;
  cout<<"Building Queue"<<endl;
}
MyQueue::~MyQueue(void){
  cout<<"clearing the queue"<<endl;
  mynode *aux;
  while(first!=NULL){
    aux=first;
    first=aux->next;
    if(first==NULL)
      last=first;   //first=last=NULL => queue is empty
    delete(aux);
    aux=NULL;
  }
  queue_size=0;
}
bool MyQueue::pushBack(int item){
  //cout<<"executing push_back"<<endl;
  mynode *aux;
  aux=new mynode;
  if(first==NULL)
    first=aux;
  aux->data=item;
  aux->next=NULL;
  if(last!=NULL)
    last->next=aux;
  last=aux;
  queue_size++;
  return true;
}
int MyQueue::pullFront(void){
  //cout<<"executing pull_front"<<endl;
  int item;
  mynode *aux=first;
  item=aux->data;
  first=aux->next;
  if(first==NULL)
    last=NULL;
  delete(aux);
  aux=NULL;
  queue_size--;
  return item;
}
bool MyQueue::isEmpty(void){
  if(first==NULL){
    cout<<"queue empty"<<endl;
    return true;
  }
  else{
    cout<<"queue isn't empty"<<endl;
    return false;
  }
}
int MyQueue::getSize(void){
  cout<<"the size of queue is: "<<queue_size<<endl;
  return queue_size;
}
void MyQueue::readQueue(void){
  cout<<"reading the queue"<<endl;
  mynode* aux;
  aux=first;
  while(aux!=NULL){
    cout<<aux->data<<", ";
    aux=aux->next;
  }
  cout<<"\n"<<endl;
}
