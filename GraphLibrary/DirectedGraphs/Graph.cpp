#include "Graph.h"
#include <iostream>
//***********************************
//Bag Definitions

//Initialization for the Bag class, the position, and pointers are set to the start of the adjacency list.
Bag::Bag(){
	Head = new LinkedList();
	CurrentPos = Head;
	Iterator = Head;
	position = 0;
	Head->Next = 0;
}

//All linked list are deleted, by iterating over the Next attribute of the Linked List class.
Bag::~Bag(){
	while(Head != 0){
		CurrentPos = Head->Next;
		delete Head;
		Head = CurrentPos;
	}
}

//Adds data, when add the end of the current LinkedList it will create a new Linked List.
void Bag::Add(int Data){
	if(CurrentPos->IsEnd()){
		CurrentPos->Next = new LinkedList();
		CurrentPos =  CurrentPos->Next;
		CurrentPos->Next = 0;
	}
	
	CurrentPos->Add(Data);
}

//Used to set the Iteration values to the beginning.
void Bag::BeginIter(){
	position = 0;
	Iterator = Head;
}

//Used to get the next value in the adjacency list.
int Bag::Next(){

	if(Iterator->IsEnd(position)){
		Iterator = Iterator->Next;
		position = 0;
	}
	return Iterator->GetData(position++);

}

//Used to know if the Bag is Empty
bool Bag::IsEmpty(){
	return Head==0;
}

//************************************

//************************************

Graph::Graph(int V){
	Adj = new Bag *[V];
	NumVert = V;
	NumEdg = 0;
	Type = NonDirected;
	for(int i = 0; i<V; ++i)
		Adj[i] = new Bag();
}

Graph::Graph(int V, GraphType GType){
	Adj = new Bag *[V];
	NumVert = V;
	NumEdg = 0;
	Type = GType;
	for(int i = 0; i<V; ++i)
		Adj[i] = new Bag();
}

Graph::~Graph(){
	delete Adj;
}

void Graph::addEdge(int v1, int v2){
	Adj[v1]->Add(v2);
	if(Type == NonDirected)
		Adj[v2]->Add(v1);
	NumEdg++;
}

int main(){
	Graph Prueba(12, Directed);
	for (int a = 0; a < 12; a++)
		for(int b = 0; b < 12; b++)
			Prueba.addEdge(a,b);
	for(int a = 0; a<12 ; ++a) {
		Bag *Temp = Prueba.Iterator(a);
		Temp->BeginIter();
		while(Temp->HasNext())
			std::cout<<Temp->Next()<<" ";
		std::cout<<std::endl;
	}
}
