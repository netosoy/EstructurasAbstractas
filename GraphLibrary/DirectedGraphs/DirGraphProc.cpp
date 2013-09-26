#include "DirGraphProc.h"
#include "Graph.h"
/*
Iterable Class Description

Iterable::Iterable(int size){
	Data = new int(size);
	length = size;
	counter = 0;
}

bool Iterable::HasNext(){
	return counter < size;
}

int Iterable::Next(){
	return Data[
}

Iterable::~Iterable(){

}
*/
//***********************************
//Directed DFS procedure

DirectedDFS::DirectedDFS(Graph& G, int s){
	marked = new bool(G.V());
	for(int i=0; i < G.V(); i++)
		marked[i] = false;
	dfs(G, s);
}

DirectedDFS::DirectedDFS(Graph& G, int *s, int elements){
	marked = new bool(G.V());
	for(int a = 0; a< elements; ++a)
		if(!marked[s[a]])
			dfs(G,s[a]);
}

void DirectedDFS::dfs(Graph& G, int v){
	marked[v] = true;
	Bag *TempBag = G.Iterator(v);
	TempBag->BeginIter();
	int iter;
	while(TempBag->HasNext())
		if(!marked[(iter = TempBag->Next())])
			dfs(G,iter);
}

//**********************************

//Directed Cycle algorithm

DirectedCycle::DirectedCycle(Graph& G){
	onStack = new bool(G.V());
	edgeTo = new int(G.V());
	marked = new bool(G.V());
	for(int v = 0; v<G.V(); ++v)
		if(!marked[v])
			dfs(G, v);	
}

void DirectedCycle::dfs(Graph& G, int v){
	onStack[v] = true;
	marked[v] = true;
	Bag *Temp = G.Iterator(v);
	Temp->BeginIter();
	int w;
	while(Temp->HasNext()){
		w = Temp->Next();
		if(hasCycle())
			return;
		else{
			if(!marked[w]){
				edgeTo[w] = v;
				dfs(G,w);
			} else if (onStack[w]){
				for(int x = v; x != w; x = edgeTo[x])
					cycle.push(x);
				cycle.push(w);
				cycle.push(v);
			}
		}			
	}
	onStack[v] = false;
}

bool DirectedCycle::hasCycle(){
	return !cycle.empty();
}

std::stack<int> *DirectedCycle::GetCycle(){
	return &cycle;
}

//**********************************

//DepthFirstOrder class description

DepthFirstOrder::DepthFirstOrder(Graph &G){
	marked = new bool(G.V());
	
	for(int v = 0; v < G.V(); v++)
		if(!marked[v])
			dfs(G, v);
}

void DepthFirstOrder::dfs(Graph &G, int v){
	pre.push_back(v);
	marked[v] = true;
	Bag *Temp = G.Iterator(v);
	Temp->BeginIter();
	int nextVert;	
	while(Temp->HasNext()){
		nextVert = Temp->Next();
		if(!marked[nextVert])
			dfs(G,v);
	}
	post.push_back(v);
	reversePost.push_front(v);	
}

//**********************************

//Topological Sort Class description

Topological::Topological(Graph &G){
	DirectedCycle *FindCycle = new DirectedCycle(G);
	if(!FindCycle->hasCycle()){
		delete FindCycle;
		DepthFirstOrder *dfs = new DepthFirstOrder(G);
		order = dfs->GetreversePost();
	}
}
std::deque<int> *Topological::GetOrder(){
	return order;
}

bool Topological::isDAG(){
	return order != 0;
}

//*********************************
/*
//Kosaraju Algorithm

Kosaraju::Kosaraju(Graph &G){
	marked = new bool(G.V());
	id = new int(G.V());
	DepthFirstOrder *order = new DepthFirstOrder(	
}

void Kosaraju::dfs(Graph &G, int v){

}*/
