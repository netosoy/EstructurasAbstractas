#include"edge.hh"

Edge::Edge() : u(0), v(0), w(0.0){

}


Edge::Edge(int vertex1, int vertex2, float W){
	this->u=vertex1;
	this->v=vertex2;
	this->w=W;
}

float Edge::weight(){
	return w;
}

int Edge::either(){
	return v;
}

int Edge::other(int vertex){
	if(vertex==u) return v;
	else if (vertex==v) return u;
	else return 1;
}

int Edge::compareTo(Edge that){
	if(this->weight() < that.weight()) return 1;
	else if(this->weight() > that.weight()) return -1;
	else	return 0;
}

Edge& Edge::operator=(const Edge &e){
	u=e.u;
	v=e.v;
	w=e.w;
	return *this;
}
void Edge::toString(){
	cout<<u<<" "<<v<<" "<<w<<endl;

}

