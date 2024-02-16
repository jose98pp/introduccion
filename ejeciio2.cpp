#include <iostream>
using namespace std;

// Función para contar las vocales en una cadena
int vocales(char *pc) {
	int contador_vocales = 0;
	
	for (int i = 0; pc[i] != '\0'; i++) {
		switch (pc[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			contador_vocales++;
			break;
		default:
			
			break;
		}
	}
	
	cout << "Número de vocales en la cadena: " << contador_vocales << endl;
	
	return contador_vocales; 
}

int main(int argc, char *argv[]) {
	char cadena[] = "hola mundo";
	char *pc = cadena;
	

	int num_vocales = vocales(pc);
	
	
	
	return 0;
}
