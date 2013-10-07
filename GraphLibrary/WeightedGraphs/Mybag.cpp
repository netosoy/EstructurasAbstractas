#include"Mybag.hh"


MyBag::MyBag(void){
	first_element= NULL;
	N=0;
}

void MyBag::add(const Edge& arista){
	T_cell *oldfirst = first_element;
	first_element = new T_cell;
	first_element->edge = arista;
	first_element->next = oldfirst;
	N++;

}


void MyBag::beginIterate(void){
	iterator = first_element;
	position=0;
} 

Edge MyBag::getEdge(){
	T_cell * current = iterator;
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

 

//imprime BOLSAS CON OBJETOS EDGES--PRUEBA
void MyBag::print_EdgeBag(void) {
		T_cell * current;
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

	T_cell * current;
	current = first_element;  
   while (current!= NULL){
   	T_cell* next = current->next;
   	delete current;
   	current = next;
   }

}


