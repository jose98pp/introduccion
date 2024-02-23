#include <iostream>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para time()

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

// Función para generar números aleatorios y llenar el arreglo
void generar_aleatorios(int *n, int cant) {
	// Inicializar la semilla para la generación de números aleatorios
	srand(time(0));
	
	// Llenar el arreglo con números aleatorios entre 1 y 100
	for (int i = 0; i < cant; ++i) {
		n[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
	}
}

int main() {
	const int TAM = 7;
	int numeros[TAM];
	int mayor_numero = 0; // Inicializamos mayor_numero con el valor mínimo posible de un int
	
	int opcion;
	
	do {
		cout << "MENU" << endl;
		cout << "1.- Llenado de numeros aleatorios" << endl;
		cout << "2.- Impresion" << endl;
		cout << "3.- Mayor" << endl;
		cout << "4.- Buscar" << endl;
		cout << "0.- Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1:
			generar_aleatorios(numeros, TAM);
			cout << "Numeros aleatorios generados." << endl;
			break;
		case 2:
			cout << "IMPRESION RECURSIVA" << endl;
			imprec(numeros, TAM); 
			break;
		case 3:
			cout << "MAYOR RECURSIVO" << endl;
			mayor_recursiva(numeros, TAM, mayor_numero);
			cout << "El mayor número en el arreglo es: " << mayor_numero << endl;
			break;
		case 4:
			int valor_buscado;
			cout << "Ingrese el valor a buscar: ";
			cin >> valor_buscado;
			cout << "BUSQUEDA RECURSIVA" << endl;
			busqueda_recursiva(numeros, valor_buscado, TAM);
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
		}
		
	} while (opcion != 0);
	
	return 0;
}
