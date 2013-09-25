#include"stack.hh"

MyStack::MyStack(void){
  this->head=NULL;
  this->stack_size=0;
  cout<<"Building the stack"<<endl;
}
MyStack::~MyStack(void){
  cout<<"clearing the stack"<<endl;
  mynode *aux;
  while(head!=NULL){
    aux=head;
    head=aux->next;
    delete(aux);
    aux=NULL;
  }
  stack_size=0;
}
bool MyStack::push(int item){
  mynode *aux;
  aux = new mynode;
  aux->data=item;
  aux->next=head;
  head=aux;
  stack_size++;
  return true;
}
int MyStack::pull(void){
  int item;
  mynode *aux=head;  //to eliminate
  head=aux->next;
  item=aux->data;
  delete(aux);
  aux=NULL;
  stack_size--;
  return item;
}
bool MyStack::isEmpty(void){
  if (head == NULL){
    cout<<"stack empty"<<endl;
  }
  else{
    cout<<"stack isn't empty"<<endl;
  }
  return true;
}
int MyStack::getSize(void){
  cout<<"the stack size is: "<<stack_size<<endl;
  return stack_size;
}
void MyStack::readStack(void){
  cout<<"reading the stack"<<endl;
  mynode* aux;
  aux=head;
  while(aux!=NULL){
    cout<<aux->data<<", ";
    aux=aux->next;
  }
  cout<<"\n"<<endl;
}
