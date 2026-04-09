#include "Domo.h"
#include <iostream>
#include <iomanip>

namespace EIF201 {
	Domo::Domo(int codigo, typeDomo type, double capacidadOxigeno, int maxOcupantes)
		: codigo(codigo), type(type), capacidadOxigeno(capacidadOxigeno),
		maxOcupantes(maxOcupantes), sellado(false), cantidadColonos(0) {
		colonos = new Colono * [maxOcupantes];
		for (int i = 0; i < maxOcupantes; i++) {
			colonos[i] = nullptr;
		}
	}

	Domo::~Domo() {
		delete[] colonos;
	}

	int Domo::getCodigo() const {
		return codigo;
	}

	typeDomo Domo::getType() const {
		return type;
	}

	double Domo::getCapacidadOxigeno() const {
		return capacidadOxigeno;
	}

	int Domo::getMaxOcupantes() const {
		return maxOcupantes;
	}

	int Domo::getCantidadColonos() const {
		return cantidadColonos;
	}

	bool Domo::isSellado() const {
		return sellado;
	}

	std::string Domo::typeToString() const {
		switch (type) {
		case Laboratorio:
			return "Laboratorio";

		case Ingenieria:
			return "Ingenieria";

		case Habitat:
			return "Habitat";

		default:
			return "Desconocido";
		}
	}

	bool Domo::esCompatible(const Colono* colono) const {
		if (colono == 0) {
			return false;
		}
		Especiality especiality = colono->getEspeciality();

		if (type == Habitat) {
			return true;
		}
		if (type == Laboratorio) {
			return especiality == Medico || especiality == Biologo || especiality == Geologo;
		}
		if (type == Ingenieria) {
			return especiality == Ingeniero || especiality == Piloto;
		}
		return false;
	}

	bool Domo::estaLleno() const {
		return cantidadColonos >= maxOcupantes;
	}

	double Domo::consumoActual() const {
		double total = 0.0;
		for (int i = 0; i < cantidadColonos; i++) {
			total += colonos[i]->getConsumoOxigeno();
		}
		return total;
	}

	double Domo::ratioOxigeno() const {
		double consumo = consumoActual();
		if (consumo <= 0.0) {
			return capacidadOxigeno;
		}
		return capacidadOxigeno / consumo;
	}

	double Domo::ratioSiIngresa(const Colono* colono) const {
		if (colono == 0) {
			return false;
		}
		double consumo = consumoActual() + colono->getConsumoOxigeno();
		if (consumo <= 0.0) {
			return capacidadOxigeno;
		}
		return capacidadOxigeno / consumo;
	}

	bool Domo::puedeIngresar(const Colono* colono) const {
		if (colono == 0) {
			return false;
		}
		if (sellado) {
			return false;
		}
		if (estaLleno()) {
			return false;
		}
		if (!esCompatible(colono)) {
			return false;
		}

		double nuevoConsumo = consumoActual() + colono->getConsumoOxigeno();
		return nuevoConsumo <= capacidadOxigeno;
	}

	bool Domo::addColono(Colono* colono) {
		if (puedeIngresar(colono)) {
			return false;
		}
		colonos[cantidadColonos] = colono;
		cantidadColonos++;
		return true;
	}

	bool Domo::deleteColonoId(int id, Colono*& colonoEliminado) {
		if (sellado) {
			return false;
		}
		for (int i = 0; i < cantidadColonos; i++) {
			if (colonos[i]->getId() == id) {
				colonoEliminado = colonos[i];

				for (int j = 0; j < cantidadColonos - 1; j++) {
					colonos[j] = colonos[j + 1];
				}
				colonos[cantidadColonos - 1] = nullptr;
				cantidadColonos--;
				return true;
			}
		}
		return false;
	}

	int Domo::evacuacionForzosa(Colono** destino, int maxDestino) {
		int extraidos = 0;

		while (cantidadColonos > 0 && extraidos < maxDestino) {
			destino[extraidos] = colonos[cantidadColonos - 1];
			colonos[cantidadColonos - 1] = nullptr;
			cantidadColonos--;
			extraidos++;
		}
		return extraidos;
	}

	void Domo::sellar() {
		sellado = true;
	}

	void Domo::abrir() {
		sellado = false;
	}

	Colono* Domo::searchColonoId(int id) const {
		for (int i = 0; i < cantidadColonos; i++) {
			if (colonos[i]->getId() == id) {
				return colonos[i];
			}
		}
		return 0;
	}

	void Domo::mostrar() const {
		std::cout << "Domo: " << codigo << "[" << typeToString() << "]" << "- Colonos: " <<
			cantidadColonos << "/" << maxOcupantes << ", O2: " << consumoActual() << "/" <<
			capacidadOxigeno << " Ratio: " << std::fixed << std::setprecision(2) << ratioOxigeno()
			<< ", Sellado: " << (sellado ? "Si" : "No") << std::endl;

		if (ratioOxigeno() < 1.5) {
			std::cout << " (Seguro) ";
		}
		else if (ratioOxigeno() >= 1.2) {
			std::cout << " (¡Precaucion!) ";
		}
		else {
			std::cout << " (Critico!!) ";
		}
		std::cout << std::endl;

		for (int i = 0; i < cantidadColonos; i++) {
			std::cout << " - ";
			colonos[i]->mostrar();
		}
	}
}
