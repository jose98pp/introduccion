#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructura para representar un Libro
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int publicationYear;
};

// Estructura para representar un Usuario
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
};

// Estructura para representar un Bibliotecario
struct Bibliotecario {
	int employeeID;
	string nombre;
	string apellido;
	string email;
};

// Función para imprimir los datos de un libro usando punteros
void imprimirLibro(Libro* pl) {
	cout << "Titulo: " << pl->titulo << ", Autor: " << pl->autor << ", ISBN: " << pl->ISBN << ", Año: " << pl->publicationYear << "\n";
}

// Función para imprimir los datos de un usuario usando punteros
void imprimirUsuario(Usuario* pu) {
	cout << "User ID: " << pu->userID << ", Nombre: " << pu->nombre << " " << pu->apellido << ", Email: " << pu->email << "\n";
}

// Función para imprimir los datos de un bibliotecario usando punteros
void imprimirBibliotecario(Bibliotecario* pb) {
	cout << "Employee ID: " << pb->employeeID << ", Nombre: " << pb->nombre << " " << pb->apellido << ", Email: " << pb->email << "\n";
}

// Función para generar datos aleatorios para strings
string generarDatoAleatorio(string lista[], int tamano) {
	int indice = rand() % tamano;
	return lista[indice];
}

// Función para generar datos aleatorios para el Usuario
string generarEmailAleatorio(string nombre, string apellido) {
	return nombre + "." + apellido + "@upds.net.bo";
}

// Función para generar datos aleatorios para el año
int generarAnioAleatorio(int lista[], int tamano) {
	int indice = rand() % tamano;
	return lista[indice];
}

int main() {
	// Inicializar la semilla para la generación de números aleatorios
	srand(time(0));
	
	const int NUM_ELEMENTOS = 4; // Número de libros, usuarios y bibliotecarios
	
	// Arrays de datos fijos para Libros
	string listaLibros[] = {"Libro1", "Libro2", "Libro3", "Libro4", "Libro5"};
	string listaAutores[] = {"Autor1", "Autor2", "Autor3", "Autor4", "Autor5"};
	string listaISBN[] = {"1", "2", "3", "4", "5"};
	int listaAnios[] = {2000, 2005, 2010, 2015, 2020};
	
	Libro libros[NUM_ELEMENTOS];
	
	// Generar datos aleatorios para Libros
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		(libros + i)->titulo = generarDatoAleatorio(listaLibros, 5);
		(libros + i)->autor = generarDatoAleatorio(listaAutores, 5);
		(libros + i)->ISBN = generarDatoAleatorio(listaISBN, 5);
		(libros + i)->publicationYear = generarAnioAleatorio(listaAnios, 5);
	}
	
	// Arrays de datos fijos para Usuarios
	string listaNombresUsuarios[] = {"jose", "Juan", "Carlos", "Cristian ", "Matias","Efrain","Hugo","Edmundo","Eduardo"};
	string listaApellidosUsuarios[] = {"Flores", "Orosco", "Pedraza", "Peña", "Ortiz","Vilca","Herrera","Ponce"};
	
	Usuario usuarios[NUM_ELEMENTOS];
	
	// Generar datos aleatorios para Usuarios
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		(usuarios + i)->userID = i + 1;
		(usuarios + i)->nombre = generarDatoAleatorio(listaNombresUsuarios, 9);
		(usuarios + i)->apellido = generarDatoAleatorio(listaApellidosUsuarios, 8);
		(usuarios + i)->email = generarEmailAleatorio((usuarios + i)->nombre, (usuarios + i)->apellido);
	}
	
	// Arrays de datos fijos para Bibliotecarios
	string listaNombresBibliotecarios[] = {"jose", "Juan", "Carlos", "Cristian ", "Matias","Efrain","Hugo","Edmundo","Eduardo"};
	string listaApellidosBibliotecarios[] = {"Flores", "Orosco", "Pedraza", "Peña", "Ortiz","Vilca","Herrera","Ponce"};
	
	Bibliotecario bibliotecarios[NUM_ELEMENTOS];
	
	// Generar datos aleatorios para Bibliotecarios
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		(bibliotecarios + i)->employeeID = i + 1;
		(bibliotecarios + i)->nombre = generarDatoAleatorio(listaNombresBibliotecarios, 9);
		(bibliotecarios + i)->apellido = generarDatoAleatorio(listaApellidosBibliotecarios, 8);
		(bibliotecarios + i)->email = generarEmailAleatorio((bibliotecarios + i)->nombre, (bibliotecarios + i)->apellido);
	}
	
	// Imprimir resultados utilizando punteros
	cout << "Libros:\n";
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		imprimirLibro(libros + i);
	}
	
	cout << "\nUsuarios:\n";
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		imprimirUsuario(usuarios + i);
	}
	
	cout << "\nBibliotecarios:\n";
	for (int i = 0; i < NUM_ELEMENTOS; i++) {
		imprimirBibliotecario(bibliotecarios + i);
	}
	
	return 0;
}
