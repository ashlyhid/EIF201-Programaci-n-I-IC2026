#include "Vuelo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace EIF201;

double promedioPrecioConImpuesto(Vuelo** vuelos, int cantidad);

int main() {
	int cantidad;

	do {
		std::cout << "Ingrese la cantidad de vuelos a registrar (entre 1 y 10): ";
		std::cin >> cantidad;

		if (cantidad < 1 || cantidad > 10) {
			std::cout << "Valor invalido. Intente nuevamente." << std::endl;
		}
	} while (cantidad < 1 || cantidad > 10);

	Vuelo** vuelos = new Vuelo * [cantidad];

	for (int i = 0; i < cantidad; i++) {

		std::string flightCode, destinyCity;
		double price;
		int esVueloCortoPlazo;

		std::cout << "\nVuelo " << i + 1 << ":" << std::endl;

		std::cout << "Ingrese el codigo del vuelo: ";
		std::cin >> flightCode;

		std::cout << "Ingrese la ciudad de destino: ";
		std::cin >> std::ws;
		std::getline(std::cin, destinyCity);

		std::cout << "Ingrese el precio del vuelo: ";
		std::cin >> price;

		std::cout << "Ingrese el tiempo del vuelo en minutos: ";
		std::cin >> esVueloCortoPlazo;

		vuelos[i] = new Vuelo(flightCode, destinyCity, esVueloCortoPlazo, price);
	}

	for (int i = 0; i < cantidad; i++) {

		std::cout << "Vuelo N: " << vuelos[i]->getFlightCode()
			<< ", $" << std::fixed << std::setprecision(2) << vuelos[i]->getPrice()
			<< ", Destino: " << vuelos[i]->getDestinyCity()
			<< ", " << vuelos[i]->getTimeMinutes() << " minutos" << std::endl;

		if (vuelos[i]->esVueloCortoPlazo()) {
			std::cout << "El vuelo es de corto plazo.";
		}
		else {
			std::cout << "El vuelo es de largo plazo.";
		}

		std::cout << std::endl;

		std::cout << "Vuelo con impuesto: $"
			<< std::fixed << std::setprecision(2)
			<< vuelos[i]->precioConImpuesto(0.13) << std::endl;

		std::cout << "------------------------------" << std::endl;
	}

	double promedio = promedioPrecioConImpuesto(vuelos, cantidad);
	std::cout << "\nPromedio de precios con impuestos: $"
		<< std::fixed << std::setprecision(2) << promedio << std::endl;

	for (int i = 0; i < cantidad; i++) {
		delete vuelos[i];
	}
	delete[] vuelos;

	return 0;
}

double promedioPrecioConImpuesto(Vuelo** vuelos, int cantidad) {
	double suma = 0.0;

	for (int i = 0; i < cantidad; i++) {
		suma += vuelos[i]->precioConImpuesto(0.13);
	}

	return suma / cantidad;
}