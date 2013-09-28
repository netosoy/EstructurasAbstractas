#include"graph.hh"

int main(void){
  Graph my_graph(13);
  my_graph.addEdge(0,5);
  my_graph.addEdge(4,3);
  my_graph.addEdge(0,1);
  my_graph.addEdge(9,12);
  my_graph.addEdge(6,4);
  my_graph.addEdge(5,4);
  my_graph.addEdge(0,2);
  my_graph.addEdge(11,12);
  my_graph.addEdge(9,10);
  my_graph.addEdge(0,6);
  my_graph.addEdge(7,8);
  my_graph.addEdge(9,11);
  my_graph.addEdge(5,3);
  cout<<"adjacency lists"<<endl;
  for(int i=0; i<my_graph.V(); i++){
    cout<<i<<": ";
    my_graph.adjV(i);
  }
}
