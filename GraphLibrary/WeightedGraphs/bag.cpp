#include"bag.hh"


MyBag::MyBag(void){
	first_element= NULL;
	N=0;
}

void MyBag::add(int item){
	T_celda *oldfirst = first_element;
	first_element = new T_celda;
	first_element->data = item;
	first_element->next = oldfirst;
	N++;

}

void MyBag::add(const Edge& arista){
	T_celda *oldfirst = first_element;
	first_element = new T_celda;
	first_element->edge = arista;
	first_element->next = oldfirst;
	N++;

}


void MyBag::beginIterate(void){
	iterator = first_element;
	position=0;
} 

Edge MyBag::getEdge(){
	T_celda * current = iterator;
	if(iterator!=NULL) {
	iterator = iterator->next;
	}
	position++;
	return current->edge;
}

bool MyBag::isEnd(){
	if(position<this->size_of()) return true;
	else return false;

}

 

//ITERA BOLSAS CON OBJETOS EDGES--PRUEBA
void MyBag::iterate_Edge(void) {
		T_celda * current;
		current = first_element;  
      while (current!= NULL){
      	current->edge.toString();
 			current = current->next;
      }

} 

bool MyBag::is_empty(){
	return N==0;
}

int MyBag::size_of(){
	return N;
}

MyBag::~MyBag(void) {

}


