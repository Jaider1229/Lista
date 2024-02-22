#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato; 
	Nodo *siguiente;
};

void menu();
void insertarlista(Nodo *&,int);
void mostrarlista(Nodo *);
void eliminardato(Nodo *&,int);
void eliminarrepetido(Nodo *);

Nodo *lista = NULL;

int main(){
	
	menu();
	return 0;
}

void menu(){
	int opcion,dato;
	
	do{
		
	cout<<"\t. MENU \n";
	cout<<"\n1. Ingresar un numero";
	cout<<"\n2. Eliminar un numero";
	cout<<"\n3. Mostrar los datos";
	cout<<"\n4.Salir";
	cout<<"\nOpcion:   ";
	cin>>opcion;
	
	switch(opcion){
		case 1: 
		cout<<"Ingresar un numero";
		cin>>dato;
		insertarlista(lista,dato);
		break;
		
		case 2:
		cout<<"Ingrese el numero a eliminar";
		cin>>dato;
		eliminardato(lista,dato);
		break; 
		
		case 3:
		cout<<"La lista de numeros ingresasdos es:   ";
		mostrarlista(lista);
		break; 
	}
	
	}while(opcion!=4);
}

void insertarlista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato <n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista==aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo ->siguiente = aux1;
	
	cout<<"El numero "<< n <<" se ingreso correctamente";
}

void mostrarlista(Nodo *lista){
	Nodo *actual = new Nodo;
	actual=lista;
	
	while (actual!=NULL){
		
		cout<<actual->dato<<" -> ";
		actual = actual->siguiente;
	}
}
	
void eliminardato(Nodo *&lista,int n){
	
	Nodo *borrar = lista;
	Nodo *anterior = NULL;
	Nodo *borra;
    
    while(borrar != NULL) {
        if(borrar->dato == n) {
            if(anterior == NULL) {
                lista = borrar->siguiente;
                borra = borrar;
                borrar = borrar->siguiente;
                delete borra;
            } else {
                anterior->siguiente = borrar->siguiente;
                borra = borrar;
                borrar = borrar->siguiente;
                delete borra;
            }
        } else {
            anterior = borrar;
            borrar = borrar->siguiente;
        }
    }
    
    eliminarrepetido(lista);
}

	
void eliminarrepetido(Nodo *lista) {
    Nodo *actual = lista;
    Nodo *siguiente_nodo;
    Nodo *borrar;
    
    while(actual != NULL && actual->siguiente != NULL) {
        siguiente_nodo = actual;
        
        while(siguiente_nodo->siguiente != NULL) {
            if(actual->dato == siguiente_nodo->siguiente->dato) {
                borrar = siguiente_nodo->siguiente;
                siguiente_nodo->siguiente = siguiente_nodo->siguiente->siguiente;
                delete borrar;
            } else {
                siguiente_nodo = siguiente_nodo->siguiente;
            }
        }
        
        actual = actual->siguiente;
    }
}
	


