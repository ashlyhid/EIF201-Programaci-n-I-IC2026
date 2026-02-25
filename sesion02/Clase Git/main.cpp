#include <iostream>
#include "Parametros.h"	

using namespace std;



int main() {
	int numeros[tam];

	for (int i = 0; i < tam; i++) {
		cout << "Ingrese el numero " << i + 1 << ":";
		cin >> numeros[i];
	}

	cout << "\nResultados:\n";
	cout << "Mayor: " << mayor(numeros) << endl;
	cout << "Menor: " << menor(numeros) << endl;
	cout << "Suma: " << suma(numeros) << endl;
	cout << "Promedio: " << promedio(numeros) << endl;

	return 0;
}