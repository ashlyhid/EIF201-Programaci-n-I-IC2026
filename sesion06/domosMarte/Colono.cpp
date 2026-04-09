#include "Colono.h"
#include <iostream>

namespace EIF201 {
	Colono::Colono(int id, std::string name, Especiality especiality, double consumoOxigenoHora, int productividad)
		: id(id), name(name), especiality(especiality), 
		consumoOxigenoHora(consumoOxigenoHora), productividad(productividad) {
	}

	int Colono::getId() const {
		return id;
	}

	std::string Colono::getName() const {
		return name;
	}

	Especiality Colono::getEspeciality() const {
		return especiality;
	}

	double Colono::getConsumoOxigeno() const {
		return consumoOxigenoHora;
	}

	int Colono::getProductividad() const {
		return productividad;
	}

	std::string Colono::especialityToString() const {
		switch (especiality) {
		case Ingeniero: 
			return "Ingeniero";

		case Biologo:
			return "Biologo";

		case Medico:
			return "Medico";

		case Geologo:
			return "Geologo";

		case Piloto:
			return "Piloto";

		default: 
			return "Desconocida";
		}
	}

	void Colono::mostrar() const {
		std::cout << "ID: " << id << ", Nombre: " << name
			<< ", Especialidad: " << especialityToString()
			<< ", O2/h: " << consumoOxigenoHora << ", Productividad: "
			<< productividad << std::endl;
	}
}
