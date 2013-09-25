#ifndef DirGraphProc_H
#define DirGraphProc_H

#include <dequeue>
/*
class Iterable{
	public:
		Iterable(int size);
		~Iterable();
		bool HasNext();
		int Next();
	private:
		int *Data;
		int length,counter;
};
*/
class DirectedDFS{
	public:
		DirectedDFS(Graph& G, int s);
		DirectedDFS(Graph& G, int *s, int elements);
		bool Reachable(int v){return marked[v];};
	private:
		bool *marked;
		void dfs(Graph &G, int s);
};

class DirectedCycle{
	public:
		DirectedCycle(Graph& G);
		bool hasCycle();
		bool hasCycle();
		std::stack<int> *GetCycle();
		
	private:
		std::stack<int> cycle;
		bool *marked;
		int *edgeTo;
		bool *onStack;
		void dfs(Graph G, int v);
};

class DepthFirstOrder{
	public:
		DepthFirstOrder(Graph& G);
		std::dequeue *pre(){return &pre;}
		std::dequeue *post(){return &post;}
		std::dequeue *reversePost(){return &reversePost;}
	private:
		bool *marked;
		std::dequeue<int> pre;
		std::dequeue<int> post;
		std::dequeue<int> reversePost;
		void dfs(Graph &G, int v);	
};

class Topological{
	public:
		Topological(Graph &G);
		std::dequeue *GetOrder();
		bool isDAG();
	private:
		int *order
};

class Kosaraju{
	public:
		Kosaraju(Graph &G);
		bool stronglyConnected(int v, int w){return id[v] == id[w];}
		int id(int v) {return id[v];}
		int count() {return count;}
	private:
		bool *marked;
		int *id;
		int count;
		void dfs(Graph &G, int v);
};
#endif
