#include "Vuelo.h"
#include <iostream>
#include <iomanip>

namespace EIF201 {
	Vuelo::Vuelo(std::string flightCode, std::string destinyCity, int timeMinutes, double price)
		: flightCode(flightCode), destinyCity(destinyCity), timeMinutes(timeMinutes), price(price) {
	}

	Vuelo::~Vuelo() {

	}

	std::string Vuelo::getFlightCode() const {
		return flightCode;
	}

	std::string Vuelo::getDestinyCity() const {
		return destinyCity;
	}

	int Vuelo::getTimeMinutes() const {
		return timeMinutes;
	}

	double Vuelo::getPrice() const {
		return price;
	}

	bool Vuelo::esVueloCortoPlazo() const {
		int time = 0;
		if (time <= 90) {
			return true;
		}
		else {
			return false;
		}
	}

	double Vuelo::precioConImpuesto(double tasa) const {
		tasa = 0.13;
		double finalPrice = (1 + tasa);
		return 0;
	}
}
