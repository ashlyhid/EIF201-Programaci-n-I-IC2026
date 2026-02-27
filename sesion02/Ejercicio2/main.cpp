#include <iostream>
#include "Invertido.h"


using namespace std;

int main() {
	int tam;

	do {
		cout << "Ingrese el tamanio del arreglo (entre 1 y 20): ";
		cin >> tam;

		if (tam <= 0 || tam > 20) {
			cout << "ERROR: El tamanio debe estar entre 1 y 20.\n";
		}
	} while (tam <= 0 || tam > 20);

	int original[20];
	int invertido[20];

	cout << "\nIngrese los valores del arreglo:\n";
	for (int i = 0; i < tam; i++) {
		cout << "Elemento [" << i << "]: ",
			cin >> original[i];
	}
	invertir(original, invertido, tam);

	cout << "\nArreglo original:\n";
	for (int i = 0; i < tam; i++) {
		cout << original[i] << " ";
	}

	cout << "\nArreglo invertido:\n";
	for (int i = 0; i < tam; i++) {
		cout << invertido[i] << " ";
	}
	cout << endl;

	return 0;
}
