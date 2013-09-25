#include "stack.hh"

int main(void){
  MyStack my_stack;
  my_stack.getSize();
  my_stack.isEmpty();
  cout<<"pushing data"<<endl;
  for(int i=100; i<110; i++){
    my_stack.push(i);
  }
  my_stack.getSize();
  my_stack.isEmpty();
  my_stack.readStack();
  cout<<"pulling data"<<endl;
  for(int i=0; i<8; i++){
    cout<<i<<". )"<<my_stack.pull()<<endl;
  }
  my_stack.getSize();
  my_stack.isEmpty();
  return 0;
}
