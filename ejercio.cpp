#include <iostream>
#include <string>

int main() {
    int numero1, numero2, numero3;//introducimos las variables
    std::string resultado;

    std::cout << "Primer numero: ";//pide el primer numero
    std::cin >> numero1;//lo guarda el numero 
    std::cout << "Segundo numero: ";
    std::cin >> numero2;
    std::cout << "Tercer numero: ";
    std::cin >> numero3;
// va a preguntar si cada numero es mayor el seguno y al tercero y asi sucesivamente hasta en contrar el mayor 
    if (numero1 > numero2 && numero1 > numero3) {
        resultado = "El primer numero es el mas grande de los tres\n";
    } else if (numero2 > numero1 && numero2 > numero3) {
        resultado = "El segundo numero es el mas grande de los tres\n";
    } else {
        resultado = "El tercer numero es el mas grande de los tres\n";
    }
    std::cout << resultado;// el resultado es tipo string 

    return 0;
}