#include"undirGraph.hh"
#include"undirGraphProc.hh"

int main(void){
  bool isconn=true;
  Graph graph(8);
  graph.addEdge(0,5);
  graph.addEdge(2,4);
  graph.addEdge(2,3);
  graph.addEdge(1,2);
  graph.addEdge(0,1);
  graph.addEdge(3,4);
  graph.addEdge(3,5);
  graph.addEdge(0,2);
  graph.addEdge(6,7);
  DepthFirstSearch connect(graph, 2);
  for(int i=0; i<graph.V(); i++)
    if(!connect.Marked(i)) isconn=false;
  if(isconn)
    cout<<"connected graph"<<endl;
  else 
    cout<<"unconnected graph"<<endl;
}


  /*
  Graph my_graph(13);
  MyBag* iterator;
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
    iterator=my_graph.adjV(i);
    iterator->beginIte();
    cout<<i<<": ";
    while(iterator->hasNext()){
      cout<<iterator->next()<<" ";
    }
    cout<<endl;
  }
  Search my_search(&my_graph,4);
  cout<<"el número de vertices adyacentes a 4 es: "<<my_search.count()<<endl;
  cout<<"los vertices conectados a 4 son: ";
  for(int i=0; i<my_graph.V(); i++){
    if(my_search.marked(i))
      cout<<i<<" ";
  }
  cout<<endl;

}
  */
