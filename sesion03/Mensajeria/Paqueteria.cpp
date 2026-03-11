#include "Paqueteria.h"
#include <iostream>

double* crearRegistro(int& cantidad) {
	do {
		std::cout << "Ingrese la cantidad de paquetes: ";
		std::cin >> cantidad;

		if (cantidad <= 0) {
			std::cout << "ERROR: La cantidad debe ser mayor a 0.\n";
		}
	}
	while (cantidad <= 0);

	double* pesos = new double[cantidad];
	return pesos;
}

void ingresarPesos(double* pesos, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		do {
			std::cout << "Ingrese el peso del paquete " << (i + 1) << ": ";
			std::cin >> pesos[i];

			if (pesos[i] <= 0) {
				std::cout << "ERROR: el peso debe ser mayor a 0Kg.\n";
			}
		} while (pesos[i] <= 0);
	}
}

double calcularPesoTotal(const double* pesos, int cantidad) {
	double suma = 0.0;
	for (int i = 0; i < cantidad; i++) {
		suma += pesos[i];
	}
	return suma;
}

int contarSobreLimite(const double* pesos, int cantidad, double limite) {
	int contador = 0;

	std::cout << "\nPaquetes que sobrepasan el limite (" << limite << " kg):\n";
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > limite) {
			std::cout << "Paquete " << (i + 1) << " con peso: " << pesos[i] << " kg" << std::endl;
			contador++;
		}
	}
	return contador;
}

const double* buscarMasPesado(const double* pesos, int cantidad) {
	const double* mayor = &pesos[0];
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > *mayor) {
			mayor = &pesos[i];
		}
	}
	return mayor;
}