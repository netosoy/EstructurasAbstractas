#include"bag.hh"

int main(void){
  MyBag my_bag;
  my_bag.getSize();
  my_bag.isEmpty();
  cout<<"adding data"<<endl;
  my_bag.addData(5);
  my_bag.addData(3);
  my_bag.addData(-1);
  my_bag.getSize();
  my_bag.isEmpty();
  my_bag.readBag();
}
