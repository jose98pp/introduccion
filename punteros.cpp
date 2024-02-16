#include <iostream>
using namespace std;

// Definición de la función para imprimir los elementos del arreglo
void imprimiArreglo(int *pi, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << "arr[" << i << "]=" << *(pi + i) << " - ";
		cout << endl;
	}
}

// Definición de la función para imprimir los elementos del arreglo 2 solo con puntero
void imprimiArreglo2(int *pi) {
	for (;*p!=‘\0‘;++pi){
		cout<<*pi<< " ";
	}
	cout<<endl
	}
	

// Definición de la función para modificar los elementos del arreglo
void modArrreglo(int *pi, int tam, int incremento) {
	for (int i = 0; i < tam; ++i)
		*(pi + i) += incremento;
}

int main(int argc, char *argv[]) {
	const int TAM = 5; // Cantidad de elementos del arreglo
	int iarreglo[TAM] = {1, 2, 3, 4, 5}; // Declaración e inicialización del arreglo
	int *pi = iarreglo; // Declaración de un puntero que apunta al arreglo
	
	// Llamada a la función para imprimir los valores originales del arreglo
	cout << "Arreglo original:" << endl;
	imprimiArreglo(pi, TAM);
	
	// Llamada a la función para modificar los valores del arreglo
	modArrreglo(pi, TAM, 10);
	
	// Llamada a la función para imprimir los valores modificados del arreglo
	cout << "Arreglo modificado:" << endl;
	imprimiArreglo(pi, TAM);
	
	return 0; // Retorno de éxito
}
