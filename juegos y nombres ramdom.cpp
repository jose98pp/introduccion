#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Definición de constantes para el tamaño de los arrays
const int TAMJ = 3; // Tamaño de lista de juegos 
const int MNOMBRE = 6; // Tamaño de nombres de personas disponibles
const int MJUEGOS = 8; // Tamaño de nombres de juegos disponibles

// Definición de la estructura Juego
struct Juego {
	string nombre; // Nombre del juego
	int ranking; // Valoración del juego (rango del 1 al 10)
	bool tipo; // Tipo de juego (offline o online)
	string des; // Descripción opcional del juego
};

// Definición de la estructura Persona
struct Persona {
	string nombre; // Nombre de la persona
	int id_persona; // Identificador único de la persona
	Juego juegos[TAMJ]; // Array de juegos que le gustan a la persona
};

// Arrays de nombres de personas y juegos, y descripciones de juegos
string nombres_personas[] = {"Juan Perez", "Maria Flor", "Pedro Vaca", "Edmundo Flores", "Cristian Ponce", "Matias Valencia"};
string nombres_juegos[] = {"God Of War", "Age of Empire", "Dota", "Tetris", "PES 2013", "FIFA 2005", "CSGO", "Left 4dead 2"};
string descripciones_juegos[] = {"Un juego de acción y aventura", "Un juego de estrategia en tiempo real", "Un juego de estrategia en equipo", "Un clásico juego de bloques", "Un juego de fútbol", "Un juego de fútbol", "Un juego de disparos en primera persona", "Un juego de disparos en primera persona"};

// Función para generar un número aleatorio entre 0 y max-1
int randomico(int max) {
	srand(static_cast<unsigned int>(time(0)));
	return rand() % max;
}

// Función para verificar si un nombre ya está repetido en el array de personas
bool repetidos(string n, Persona personas[], int cant) {
	for (int i = 0; i < cant; i++) {
		if (n.compare(personas[i].nombre) == 0)
			return true; // Si encuentra un nombre igual, devuelve true
	}
	return false; // Si no encuentra nombres iguales, devuelve false
}

// Función para llenar los datos de las personas y sus juegos favoritos
void llenar(Persona personas[], int cant) {
	for (int i = 0; i < cant; i++) {
		string nombre_persona;
		do {
			nombre_persona = nombres_personas[randomico(MNOMBRE)]; // Selecciona un nombre aleatorio
		} while (repetidos(nombre_persona, personas, i)); // Verifica si el nombre ya ha sido usado
		
		personas[i].nombre = nombre_persona; // Asigna el nombre a la persona
		personas[i].id_persona = i + 1; // Asigna un ID único a la persona
		
		for (int j = 0; j < TAMJ; j++) { // Llenar los juegos favoritos de la persona
			int juego_index;
			bool juegos_repetidos;
			do {
				juegos_repetidos = false;
				juego_index = randomico(MJUEGOS); // Selecciona un juego aleatorio
				for (int k = 0; k < j; k++) {
					if (personas[i].juegos[k].nombre.compare(nombres_juegos[juego_index]) == 0) {
						juegos_repetidos = true; // Verifica si el juego ya ha sido asignado
						break;
					}
				}
			} while (juegos_repetidos); // Repite el proceso si el juego ya ha sido asignado
			
			personas[i].juegos[j].nombre = nombres_juegos[juego_index]; // Asigna el nombre del juego
			personas[i].juegos[j].ranking = randomico(10) + 1; // Asigna una valoración aleatoria al juego (rango del 1 al 10)
			personas[i].juegos[j].tipo = randomico(2); // Asigna un tipo de juego aleatorio (0 para offline, 1 para online)
			personas[i].juegos[j].des = descripciones_juegos[juego_index]; // Asigna la descripción del juego
		}
	}
}

// Función para imprimir los datos de las personas y sus juegos favoritos
void imprimir(Persona personas[], int cant) {
	for (int i = 0; i < cant; i++) {
		cout << "Nombre: " << personas[i].nombre << endl;
		cout << "ID: " << personas[i].id_persona << endl;
		cout << "Juegos que le gustan:" << endl;
		for (int j = 0; j < TAMJ; j++) {
			cout << "  Nombre del juego: " << personas[i].juegos[j].nombre << endl;
			cout << "  Descripción: " << personas[i].juegos[j].des << endl;
			cout << "  Ranking: " << personas[i].juegos[j].ranking << endl;
			cout << "  Tipo: " << (personas[i].juegos[j].tipo ? "Online" : "Offline") << endl;
		}
		cout << endl;
	}
}

// Función para imprimir el juego con el mayor ranking para cada persona
void valoracion(Persona personas[], int cant) {
	cout << "Juego con el mayor ranking por persona:" << endl;
	for (int i = 0; i < cant; i++) {
		cout << "Persona: " << personas[i].nombre << endl;
		cout << "ID: " << personas[i].id_persona << endl;
		
		// Encontrar el juego con el mayor ranking para esta persona
		int max_ranking = 0; // Inicializar el mayor ranking como 0
		Juego mejor_juego; // Variable para almacenar el juego con el mayor ranking
		
		for (int j = 0; j < TAMJ; j++) {
			if (personas[i].juegos[j].ranking > max_ranking) {
				max_ranking = personas[i].juegos[j].ranking; // Actualizar el mayor ranking
				mejor_juego = personas[i].juegos[j]; // Almacenar el juego con el mayor ranking
			}
		}
		
		// Imprimir el juego con el mayor ranking para esta persona
		cout << "Juego: " << mejor_juego.nombre << " - Ranking: " << mejor_juego.ranking << endl;
		
		cout << endl;
	}
}


// Función para mostrar el menú de opciones
void menu() {
	cout << "1) Llenado de personas." << endl;
	cout << "2) Impresion de personas." << endl;
	cout << "3) Valoración de juegos por persona." << endl;
	cout << "0) Salir" << endl;
}

// Función principal
int main() {
	const int MAX_PERSONAS = 4; // Número máximo de personas
	
	Persona personas[MAX_PERSONAS]; // Array de personas
	
	int opcion;
	do {
		menu(); // Muestra el menú de opciones
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenar(personas, MAX_PERSONAS); // Llenado de datos de personas y juegos
			break;
		case 2:
			imprimir(personas, MAX_PERSONAS); // Impresión de datos de personas y juegos
			break;
		case 3:
			valoracion(personas, MAX_PERSONAS); // Valoración de juegos por persona
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcion != 0); // Repetir hasta que se seleccione la opción de salir
	
	return 0;
}
