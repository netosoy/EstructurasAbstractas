#include"edge.hh"

Edge::Edge() : v(0), w(0), weight(0){

}


Edge::Edge(int vertex1, int vertex2, float weight){
	this->v=vertex1;
	this->w=vertex2;
	this->weight=weight;
}

float Edge::Weight(){
	return weight;
}

int Edge::either(){
	return v;
}

int Edge::other(int vertex){
	if(vertex==v) return w;
	else if (vertex==w) return v;
	else return 1;
}

int Edge::compareTo(Edge that){
	if(this->Weight() < that.Weight()) return 1;
	else if(this->Weight() > that.Weight()) return -1;
	else	return 0;
}

void Edge::toString(){
	cout<<v<<" "<<w<<" "<<weight<<endl;

}

