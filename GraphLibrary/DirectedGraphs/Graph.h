#ifndef LinkedList_H
#define LinkedList_H
class LinkedList{
	public:
		LinkedList(){
			Next = 0;
			PosCount = 0;
			atEnd = false;
		}
		~LinkedList(){}
		bool IsEnd(){return atEnd;}
		bool IsEnd(int Position){return PosCount == Position;}
		int GetData(int Index) {return DataList[Index];}
		void Add(int Data){
			DataList[PosCount] = Data;
			atEnd = (++PosCount%50) ? false : true;
		}
		LinkedList *Next;
		int PosCount;
	private:
		int DataList[50];
		bool atEnd;
	//	static const VecSize = 50;
};
#endif

#ifndef Bag_H
#define Bag_H
class Bag{
	public:
		Bag();
		~Bag();
		void Add(int Data);
		bool HasNext(){ 
			return !(Iterator->Next == 0 && position == CurrentPos->PosCount);
		}
		int Next();
		bool IsEmpty();
		void BeginIter();
	private:
		LinkedList *CurrentPos, *Head, *Iterator;
		int position;
};
#endif

#ifndef Graph_H
#define Graph_H
enum GraphType {Directed, NonDirected};
class Graph{
	public:
		Graph(int V);
		Graph(int V, GraphType GType);
		~Graph();	
		int V(){return NumVert;}
		int E(){return NumEdg;}
		void addEdge(int v1, int v2);
		Bag *Iterator(int v) {return Adj[v];} 	
	private:
		int NumVert, NumEdg;
		Bag **Adj; 
		GraphType Type;
};
#endif
