#include"queue.hh"

int main(void){
  MyQueue my_queue;
  my_queue.getSize();
  my_queue.isEmpty();
  cout<<"pushing data"<<endl;
  for(int i=100; i<110; i++){
    my_queue.pushBack(i);
  }
  my_queue.getSize();
  my_queue.isEmpty();
  my_queue.readQueue();
  cout<<"pulling data"<<endl;
  for(int i=0; i<7; i++){
    cout<<".) "<<my_queue.pullFront()<<endl;
  }
  my_queue.getSize();
  my_queue.isEmpty();
}
