#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TAM = 5;

struct strTiempo {
	int hora;
	int minuto;
	int segundo;
};

struct strFecha {
	int anio;
	int mes;
	int dia;
};

int randomicaHora() {
	return rand() % 24; // Genera un número aleatorio entre 0 y 23 (para horas)
}

int randomicaMinuto() {
	return rand() % 60; // Genera un número aleatorio entre 0 y 59 (para minutos)
}

int randomicaSegundo() {
	return rand() % 60; // Genera un número aleatorio entre 0 y 59 (para segundos)
}

int randomicaDia() {
	return rand() % 32; // Genera un número aleatorio entre 0 y 31 (para días)
}

int randomicaMes() {
	return rand() % 13; // Genera un número aleatorio entre 0 y 12 (para meses)
}

int randomicaAnio() {
	return 2000 + rand() % 25; // Genera un número aleatorio entre 2000 y 2024 (para años)
}

void llenado(strTiempo t[], int cant) {
	for (int i = 0; i < cant; ++i) {
		t[i].hora = randomicaHora();
		t[i].minuto = randomicaMinuto();
		t[i].segundo = randomicaSegundo();
	}
}

void llenado(strFecha f[], int cant) {
	for (int i = 0; i < cant; ++i) {
		f[i].anio = randomicaAnio();
		f[i].mes = randomicaMes();
		f[i].dia = randomicaDia();
	}
}

void imprimir(strTiempo t[], int cant) {
	cout << "Imprimiendo tiempos:" << endl;
	for (int i = 0; i < cant; ++i) {
		cout << "Tiempo " << i + 1 << ": " << t[i].hora << ":" << t[i].minuto << ":" << t[i].segundo << endl;
	}
}

void imprimir(strFecha f[], int cant) {
	cout << "Imprimiendo fechas:" << endl;
	for (int i = 0; i < cant; ++i) {
		cout << "Fecha " << i + 1 << ": " << f[i].anio << "/" << f[i].mes << "/" << f[i].dia << endl;
	}
}

int main() {
	srand(time(nullptr)); // Inicializa la semilla para generar números aleatorios
	
	strTiempo t[TAM];
	strFecha f[TAM];
	
	llenado(t, TAM); // Llena el array de estructuras strTiempo
	llenado(f, TAM); // Llena el array de estructuras strFecha
	
	imprimir(t, TAM); // Imprime el array de estructuras strTiempo
	imprimir(f, TAM); // Imprime el array de estructuras strFecha
	
	return 0;
}
