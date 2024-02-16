#include <iostream>
#include <ctime>
using namespace std;

const int TMA = 5; // Definir el tamaño del array vt

// Definir la estructura tiempo
typedef struct {
	int hora;
	int minuto;
	int segundo;
} tiempo;

// Generar un número aleatorio entre 0 y 23 para la hora
int horaRand() {
	return rand() % 24;
}

// Generar un número aleatorio entre 0 y 59 para el minuto y el segundo
int msRand() {
	return rand() % 60;
}

// Función para agregar horas aleatorias al array vt
void agregar(tiempo vt[], int tam) {
	for (int i = 0; i < tam; ++i) {
		vt[i].hora = horaRand();
		vt[i].minuto = msRand();
		vt[i].segundo = msRand();
	}
}

// Función para imprimir un array de tiempos
void imprimir(tiempo vt[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << "Hora " << i << ": " << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	tiempo vt[TMA]; // Definir un array vt de tamaño TMA
	
	// Inicializar la semilla para generar números aleatorios
	srand(clock());;
	
	
	agregar(vt, TMA);
	
	imprimir(vt, TMA);
	
	return 0;
}
