#include"bag.hh"

MyBag::MyBag(void){
  this->head=NULL;
  this->bag_size=0;
  cout<<"Building the bag"<<endl;
}
MyBag::~MyBag(void){
  cout<<"clearing the bag"<<endl;
  mynode* aux;
  while(head!=NULL){
    aux=head;
    head=aux->next;
    delete(aux);
    aux=NULL;
  }
  bag_size=0;
}
void MyBag::addData(int item){
  mynode* aux;
  aux = new mynode;
  aux->data=item;
  aux->next=head;
  head=aux;
  bag_size++;
}
bool MyBag::isEmpty(void){
  if(head==NULL){
    cout<<"bag empty"<<endl;
    return true;
  }
  else{
    cout<<"bag isn't empty"<<endl;
    return false;
  }
}
int MyBag::getSize(void){
  cout<<"the size of bag is: "<<bag_size<<endl;
  return bag_size;
}
void MyBag::readBag(void){
  cout<<"reading the bag"<<endl;
  mynode* aux;
  aux=head;
  while(aux!=NULL){
    cout<<aux->data<<", ";
    aux=aux->next;
  }
  cout<<endl;
}
