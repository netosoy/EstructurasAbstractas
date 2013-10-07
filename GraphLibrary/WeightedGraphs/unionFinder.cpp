#include"unionFinder.hh"

UnionFinder::UnionFinder(int N){ //Initialize component id array
	count = N;
	size = N;
	id = new int[N];
	for(int i=0; i<N; i++){
		id[i] = i;
	}
}

UnionFinder::~UnionFinder(){
	delete [] id;
}

int UnionFinder::Count(){
	return count;
}

bool UnionFinder::connected(int p, int q){
	return find(p)==find(q);
}

int UnionFinder::find(int p){
	return id[p];
}

void UnionFinder::Union(int p, int q){ //puts p and q in the same component
	int pID = find(p);
	int qID = find(q);
	//Nothing to do if p and q are already in the same component 
	if(pID==qID) return;
	//rename p's component to q's name 
	for(int i = 0; i < size; i++)
		if(id[i]==pID) id[i] = qID;
		count--;
}


