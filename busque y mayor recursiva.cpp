#include <iostream>
#include <climits>
using namespace std;

// Función para imprimir el arreglo de manera recursiva
void imprimir(int *n, int cant) {
	for (int i = 0; i < cant; i++)
		cout << i << "=" << n[i] << endl;
}

// Función para imprimir el arreglo de manera recursiva
void imprec(int *n, int cant) {
	if (cant > 0) {
		imprec(n, cant - 1);
		cout << cant - 1 << "=" << n[cant - 1] << endl;
	}
}

// Función recursiva para realizar la búsqueda de un valor en el arreglo
void busqueda_recursiva(int *n, int valor, int tam, int pos = 0) {
	// Si la posición actual es igual al tamaño del arreglo, significa que hemos recorrido todo el arreglo sin encontrar el valor
	if (pos == tam) {
		cout << "El valor " << valor << " no se encuentra en el arreglo" << endl;
		return;
	}
	// Si el elemento en la posición actual es igual al valor que buscamos, lo hemos encontrado
	if (n[pos] == valor) {
		cout << "El valor " << valor << " se encuentra en la posición " <<pos << endl;
		return;
	}
	// Llamada recursiva con la siguiente posición en el arreglo
	busqueda_recursiva(n, valor, tam, pos+ 1);
}

// Función recursiva para encontrar el mayor número en el arreglo
void mayor_recursiva(int *n, int cant, int &m) {
	// Si no quedan elementos en el arreglo, terminamos la recursión
	if (cant == 0)
		return;
	
	// Si el último elemento del arreglo es mayor que el máximo encontrado hasta ahora, actualizamos el máximo
	if (n[cant - 1] > m)
		m = n[cant - 1];
	
	// Llamada recursiva con el tamaño reducido del arreglo
	mayor_recursiva(n, cant - 1, m);
}

// Función principal
int main() {
	const int TAM = 7;
	int numeros[] = {3, 4, 5, 8, 1, 7, 4};
	int mayor_numero = 0; // Inicializamos mayor_numero con el valor mínimo posible de un int
	
	// Impresión recursiva del arreglo
	cout << "IMPRESION RECURSIVA" << endl;
	imprec(numeros, TAM); 
	
	// Búsqueda recursiva del valor 8 en el arreglo
	cout << "BUSQUEDA RECURSIVA" << endl;
	busqueda_recursiva(numeros, 8, TAM); 
	
	// Encontrar el mayor número en el arreglo de forma recursiva
	cout << "MAYOR RECURSIVO" << endl;
	mayor_recursiva(numeros, TAM, mayor_numero); 
	
	// Imprimir el resultado del mayor número en el arreglo
	cout << "El mayor número en el arreglo es: " << mayor_numero << endl; 
	
	return 0;
}
