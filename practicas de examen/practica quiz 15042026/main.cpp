#include "Vuelo.h"
#include <iostream>

using namespace EIF201;

int main() {
	Vuelo vuelo1("AA597", "Hong Kong", 4500, 10);
	Vuelo vuelo2("AA761", "Seoul", 6700, 15);

	std::cout << "Vuelo N: " << vuelo1.getFlightCode() << ", " << vuelo1.getDestinyCity() <<
		", $" << vuelo1.getPrice() << " ," << vuelo1.getTimeMinutes() << " minutos" << std::endl;

	if (vuelo1.esVueloCortoPlazo()) {
		std::cout << "El vuelo es de corto plazo." << std::endl;
	}
	else {
		std::cout << "El vuelo es de largo plazo." << std::endl;
	}

	std::cout << "Vuelo con impuesto: $" << vuelo1.precioConImpuesto(0.13) << std::endl;

	std::cout << "------------------------------" << std::endl;

	std::cout << "Vuelo N: " << vuelo2.getFlightCode() << ", " << vuelo2.getDestinyCity() <<
		", $" << vuelo2.getPrice() << " ," << vuelo2.getTimeMinutes() << " minutos" << std::endl;

	if (vuelo2.esVueloCortoPlazo()) {
		std::cout << "El vuelo es de corto plazo." << std::endl;
	}
	else {
		std::cout << "El vuelo es de largo plazo." << std::endl;
	}

	std::cout << "Vuelo con impuesto: $" << vuelo2.precioConImpuesto(0.13) << std::endl;

	std::cout << "------------------------------" << std::endl;

	return 0;
}