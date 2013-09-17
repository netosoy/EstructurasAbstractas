#include"dataStruc.hh"

MiPila::MiPila(void){
	primer_elemento= NULL;
	N=0;
}

void MiPila::push(int item){   // Se agregan elementos al inicio de la pila
	T_celda *oldfirst = primer_elemento;
	primer_elemento = new T_celda;
	primer_elemento->dato = item;
	primer_elemento->proximo = oldfirst;
	N++;

}
int MiPila::pull(void) { // Se quitan elementos al inicio de la pila
      if (primer_elemento == NULL) {
         cout << "\nStack Empty.";
         return NULL;
      }
      int item = primer_elemento->dato;
      primer_elemento = primer_elemento->proximo;
      N--;

      return item;

}  

bool MiPila::is_empty(){
	return N==0;
}

int MiPila::size_of(){
	return N;
}

void MiPila::iterate(void) {
		T_celda * conductor;
		conductor = primer_elemento;
      cout<<"Contenido de la estructura"<< endl;
      while (conductor!= NULL){
      	cout<< conductor->dato << " ";
 			conductor = conductor->proximo;
		}
}


MiPila::~MiPila(void) {
}
     
MiQueue::MiQueue(void){
	primer_elemento= NULL;
	ultimo_elemento= NULL;
	N=0;
}

void MiQueue::enqueue(int item){ // Se agregan elementos al final de la cola
	T_celda *oldlast = ultimo_elemento; 
	ultimo_elemento = new T_celda;
	ultimo_elemento->dato = item;
	ultimo_elemento->proximo = NULL; // El final apunta a NULL
	if(MiQueue::is_empty())
		primer_elemento = ultimo_elemento;
	else oldlast->proximo = ultimo_elemento;
	N++;

}
int MiQueue::dequeue(void) { // Se quitan elementos al final de la cola 
      if (primer_elemento == NULL) {
         cout << "\nStack Empty.";
         return NULL;
      }
      int item = primer_elemento->dato;
      primer_elemento = primer_elemento->proximo;
      if(MiQueue::is_empty()) ultimo_elemento = NULL; 
      N--;
      return item;

}  

bool MiQueue::is_empty(){
	return N==0;
}

int MiQueue::size_of(){
	return N;
}
void MiQueue::iterate(void) {
		T_celda * conductor;
		conductor = primer_elemento;
      cout<<"Contenido de la estructura"<< endl;
      while (conductor!= NULL){
      	cout << conductor->dato << " ";
 			conductor = conductor->proximo;
		}
}

MiBag::MiBag(void){
	primer_elemento= NULL;
	N=0;
}

void MiBag::add(int item){
	T_celda *oldfirst = primer_elemento;
	primer_elemento = new T_celda;
	primer_elemento->dato = item;
	primer_elemento->proximo = oldfirst;
	N++;

}
void MiBag::iterate(void) {
		T_celda * conductor;
		conductor = primer_elemento;  
      while (conductor!= NULL){
      	cout<<conductor->dato << " "<<endl; ;
 			conductor = conductor->proximo;
      }
}  

bool MiBag::is_empty(){
	return N==0;
}

int MiBag::size_of(){
	return N;
}

MiBag::~MiBag(void) {
}


DeQueue::DeQueue(void){
	primer_elemento= NULL;
	ultimo_elemento= NULL;
	N=0;
}


void DeQueue::pushRight(int item){ // Se agregan elementos al final de la cola
	T_celda *oldlast = ultimo_elemento; 
	ultimo_elemento = new T_celda;
	ultimo_elemento->dato = item;
	ultimo_elemento->proximo = NULL; // El final apunta a NULL
	if(DeQueue::is_empty())
		primer_elemento = ultimo_elemento;
	else oldlast->proximo = ultimo_elemento;
	N++;

}

void DeQueue::pushLeft(int item){ // Se agregan elementos al final de la cola
	T_celda *oldfirst = primer_elemento; 
	primer_elemento = new T_celda;
	primer_elemento->dato = item;
	primer_elemento->proximo = oldfirst;
	if(DeQueue::is_empty())
		primer_elemento = ultimo_elemento;
	N++;

}

int DeQueue::popLeft(void) { // Se quitan elementos al final de la cola 
      if (primer_elemento == NULL) {
         cout << "\nStack Empty.";
         return NULL;
      }
      int item = primer_elemento->dato;
      primer_elemento = primer_elemento->proximo;
      if(DeQueue::is_empty()) ultimo_elemento = NULL; 
      N--;
      return item;

}  

bool DeQueue::is_empty(){
	return N==0;
}

int DeQueue::size_of(){
	return N;
	
}

void DeQueue::iterate(void) {
		T_celda * conductor;
		conductor = primer_elemento;
      cout<<"Contenido de la estructura"<<endl;      
      while (conductor!= NULL){
      	cout<< conductor->dato << " ";
 			conductor = conductor->proximo;
      }
}  
