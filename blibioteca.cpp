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

// Funci�n para imprimir los datos de un libro usando punteros
void imprimirLibro(Libro* pl) {
	cout << "Titulo: " << pl->titulo << ", Autor: " << pl->autor << ", ISBN: " << pl->ISBN << ", A�o: " << pl->publicationYear << "\n";
}

// Funci�n para imprimir los datos de un usuario usando punteros
void imprimirUsuario(Usuario* pu) {
	cout << "User ID: " << pu->userID << ", Nombre: " << pu->nombre << " " << pu->apellido << ", Email: " << pu->email << "\n";
}

// Funci�n para imprimir los datos de un bibliotecario usando punteros
void imprimirBibliotecario(Bibliotecario* pb) {
	cout << "Employee ID: " << pb->employeeID << ", Nombre: " << pb->nombre << " " << pb->apellido << ", Email: " << pb->email << "\n";
}

// Funci�n para generar datos aleatorios para strings
string generarDatoAleatorio(string lista[], int tamano) {
	int indice = rand() % tamano;
	return lista[indice];
}

// Funci�n para generar datos aleatorios para el Usuario
string generarEmailAleatorio(string nombre, string apellido) {
	return nombre + "." + apellido + "@upds.net.bo";
}

// Funci�n para generar datos aleatorios para el a�o
int generarAnioAleatorio(int lista[], int tamano) {
	int indice = rand() % tamano;
	return lista[indice];
}

int main() {
	// Inicializar la semilla para la generaci�n de n�meros aleatorios
	srand(time(0));
	
	// Arrays de datos fijos para Libros
	string listaLibros[] = {"Libro1", "Libro2", "Libro3", "Libro4", "Libro5"};
	string listaAutores[] = {"Autor1", "Autor2", "Autor3", "Autor4", "Autor5"};
	string listaISBN[] = {"1", "2", "3", "4", "5"};
	int listaAnios[] = {2000, 2005, 2010, 2015, 2020};
	
	const int numLibros = 3;
	Libro libros[numLibros];
	
	// Generar datos aleatorios para Libros
	for (int i = 0; i < numLibros; i++) {
		(libros + i)->titulo = generarDatoAleatorio(listaLibros, 5);
		(libros + i)->autor = generarDatoAleatorio(listaAutores, 5);
		(libros + i)->ISBN = generarDatoAleatorio(listaISBN, 5);
		(libros + i)->publicationYear = generarAnioAleatorio(listaAnios, 5);
	}
	
	// Arrays de datos fijos para Usuarios
	string listaNombresUsuarios[] = {"Usuario1", "Usuario2", "Usuario3", "Usuario4", "Usuario5"};
	string listaApellidosUsuarios[] = {"Apellido1", "Apellido2", "Apellido3", "Apellido4", "Apellido5"};
	
	const int numUsuarios = 3;
	Usuario usuarios[numUsuarios];
	
	// Generar datos aleatorios para Usuarios
	for (int i = 0; i < numUsuarios; i++) {
		(usuarios + i)->userID = i + 1;
		(usuarios + i)->nombre = generarDatoAleatorio(listaNombresUsuarios, 5);
		(usuarios + i)->apellido = generarDatoAleatorio(listaApellidosUsuarios, 5);
		(usuarios + i)->email = generarEmailAleatorio((usuarios + i)->nombre, (usuarios + i)->apellido);
	}
	
	// Arrays de datos fijos para Bibliotecarios
	string listaNombresBibliotecarios[] = {"Bibliotecario1", "Bibliotecario2", "Bibliotecario3", "Bibliotecario4", "Bibliotecario5"};
	string listaApellidosBibliotecarios[] = {"ApellidoB1", "ApellidoB2", "ApellidoB3", "ApellidoB4", "ApellidoB5"};
	
	const int numBibliotecarios = 3;
	Bibliotecario bibliotecarios[numBibliotecarios];
	
	// Generar datos aleatorios para Bibliotecarios
	for (int i = 0; i < numBibliotecarios; i++) {
		(bibliotecarios + i)->employeeID = i + 1;
		(bibliotecarios + i)->nombre = generarDatoAleatorio(listaNombresBibliotecarios, 5);
		(bibliotecarios + i)->apellido = generarDatoAleatorio(listaApellidosBibliotecarios, 5);
		(bibliotecarios + i)->email = generarEmailAleatorio((bibliotecarios + i)->nombre, (bibliotecarios + i)->apellido);
	}
	
	// Imprimir resultados utilizando punteros
	cout << "Libros:\n";
	for (int i = 0; i < numLibros; i++) {
		imprimirLibro(libros + i);
	}
	
	cout << "\nUsuarios:\n";
	for (int i = 0; i < numUsuarios; i++) {
		imprimirUsuario(usuarios + i);
	}
	
	cout << "\nBibliotecarios:\n";
	for (int i = 0; i < numBibliotecarios; i++) {
		imprimirBibliotecario(bibliotecarios + i);
	}
	
	return 0;
}
