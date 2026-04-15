#ifndef VUELO_H
#define	VUELO_H
#include <iostream>
#include <string>

namespace EIF201 {
	class Vuelo {
	private:
		std::string	flightCode;
		std::string destinyCity;
		int timeMinutes;
		double price;

	public:
		Vuelo(std::string flightCode, std::string destinyCity, int timeMinutes, double price);
		~Vuelo();
		std::string getFlightCode() const;
		std::string getDestinyCity() const;
		int getTimeMinutes() const;
		double getPrice() const;

		bool esVueloCortoPlazo() const;
		double precioConImpuesto(double tasa) const;
	};
}


#endif 
