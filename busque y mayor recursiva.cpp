#include <iostream>
#include <climits>
using namespace std;

void imprimir(int *n, int cant) {
	for (int i = 0; i < cant; i++)
		cout << i << "=" << n[i] << endl;
}

void imprec(int *n, int cant) {
	if (cant > 0) {
		imprec(n, cant - 1);
		cout << cant - 1 << "=" << n[cant - 1] << endl;
	}
}

void busqueda_recursiva(int *n, int valor, int tam, int index = 0) {
	if (index == tam) {
		cout << "El valor " << valor << " no se encuentra en el arreglo" << endl;
		return;
	}
	if (n[index] == valor) {
		cout << "El valor " << valor << " se encuentra en la posición " << index << endl;
		return;
	}
	busqueda_recursiva(n, valor, tam, index + 1);
}

void mayor_recursiva(int *n, int cant, int &m) {
	if (cant == 0)
		return;
	
	if (n[cant - 1] > m)
		m = n[cant - 1];
	
	mayor_recursiva(n, cant - 1, m);
}

int main() {
	const int TAM = 7;
	int numeros[] = {3, 4, 5, 8, 1, 7, 4};
	int mayor_numero = INT_MIN; // Inicializamos mayor_numero con el valor mínimo posible de un int
	
	cout << "IMPRESION RECURSIVA" << endl;
	imprec(numeros, TAM); // Impresión recursiva del arreglo
	cout << "BUSQUEDA RECURSIVA" << endl;
	busqueda_recursiva(numeros, 8, TAM); // Búsqueda recursiva
	cout << "MAYOR RECURSIVO" << endl;
	mayor_recursiva(numeros, TAM, mayor_numero); // Encontrar el mayor número recursivamente
	cout << "El mayor número en el arreglo es: " << mayor_numero << endl; // Imprimir el resultado
	
	return 0;
}
