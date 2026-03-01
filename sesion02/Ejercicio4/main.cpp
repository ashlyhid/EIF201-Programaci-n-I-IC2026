#include <iostream>
#include <string>
#include "Nombre.h"

using namespace std;

int main() {
	string nombreCompleto;
	cout << "Ingrese su nombre completo: ";
	getline(cin, nombreCompleto);

	cout << "\nPrimer Nombre: " << primerNombre(nombreCompleto) << endl;
	cout << "\nPrimer Apellido: " << primerApellido(nombreCompleto) << endl;
	cout << "\nSegundo Apellido: " << segundoApellido(nombreCompleto) << endl;
	cout << "\nNumero de vocales: " << vocales(nombreCompleto) << endl;
	cout << "\nNombre en mayusculas: " << convertirMayus(nombreCompleto) << endl;
	cout << "\nLongitud del nombre completo: " << longitudNombre(nombreCompleto) << endl;

	return 0;
}