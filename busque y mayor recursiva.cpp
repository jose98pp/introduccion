#include <iostream>
#include <climits>
using namespace std;

// Funci�n para imprimir el arreglo de manera recursiva
void imprimir(int *n, int cant) {
	for (int i = 0; i < cant; i++)
		cout << i << "=" << n[i] << endl;
}

// Funci�n para imprimir el arreglo de manera recursiva
void imprec(int *n, int cant) {
	if (cant > 0) {
		imprec(n, cant - 1);
		cout << cant - 1 << "=" << n[cant - 1] << endl;
	}
}

// Funci�n recursiva para realizar la b�squeda de un valor en el arreglo
void busqueda_recursiva(int *n, int valor, int tam, int pos = 0) {
	// Si la posici�n actual es igual al tama�o del arreglo, significa que hemos recorrido todo el arreglo sin encontrar el valor
	if (pos == tam) {
		cout << "El valor " << valor << " no se encuentra en el arreglo" << endl;
		return;
	}
	// Si el elemento en la posici�n actual es igual al valor que buscamos, lo hemos encontrado
	if (n[pos] == valor) {
		cout << "El valor " << valor << " se encuentra en la posici�n " <<pos << endl;
		return;
	}
	// Llamada recursiva con la siguiente posici�n en el arreglo
	busqueda_recursiva(n, valor, tam, pos+ 1);
}

// Funci�n recursiva para encontrar el mayor n�mero en el arreglo
void mayor_recursiva(int *n, int cant, int &m) {
	// Si no quedan elementos en el arreglo, terminamos la recursi�n
	if (cant == 0)
		return;
	
	// Si el �ltimo elemento del arreglo es mayor que el m�ximo encontrado hasta ahora, actualizamos el m�ximo
	if (n[cant - 1] > m)
		m = n[cant - 1];
	
	// Llamada recursiva con el tama�o reducido del arreglo
	mayor_recursiva(n, cant - 1, m);
}

// Funci�n principal
int main() {
	const int TAM = 7;
	int numeros[] = {3, 4, 5, 8, 1, 7, 4};
	int mayor_numero = 0; // Inicializamos mayor_numero con el valor m�nimo posible de un int
	
	// Impresi�n recursiva del arreglo
	cout << "IMPRESION RECURSIVA" << endl;
	imprec(numeros, TAM); 
	
	// B�squeda recursiva del valor 8 en el arreglo
	cout << "BUSQUEDA RECURSIVA" << endl;
	busqueda_recursiva(numeros, 8, TAM); 
	
	// Encontrar el mayor n�mero en el arreglo de forma recursiva
	cout << "MAYOR RECURSIVO" << endl;
	mayor_recursiva(numeros, TAM, mayor_numero); 
	
	// Imprimir el resultado del mayor n�mero en el arreglo
	cout << "El mayor n�mero en el arreglo es: " << mayor_numero << endl; 
	
	return 0;
}
