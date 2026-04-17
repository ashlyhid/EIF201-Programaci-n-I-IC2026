#include "Beneficio.h"
#include <iostream>

namespace EIF201 {

	Beneficio::Beneficio() : capacidad(5), cantidad(0) {
		lotes = new LoteCafe * [capacidad];
		for (int i = 0; i < capacidad; i++) {
			lotes[i] = nullptr;
		}
	}

	Beneficio::~Beneficio() {
		for (int i = 0; i < cantidad; i++) {
			delete lotes[i];
		}
		delete[] lotes;
	}

	void Beneficio::redimensionar() {
		int nuevaCapacidad = capacidad * 2;
		LoteCafe** nuevo = new LoteCafe * [nuevaCapacidad];

		for (int i = 0; i < nuevaCapacidad; i++) {
			nuevo[i] = nullptr;
		}

		for (int i = 0; i < cantidad; i++) {
			nuevo[i] = lotes[i];
		}

		delete[] lotes;
		lotes = nuevo;
		capacidad = nuevaCapacidad;
	}

	void Beneficio::agregarLote(LoteCafe* lote) {
		if (cantidad == capacidad) {
			redimensionar();
		}
		lotes[cantidad] = lote;
		cantidad++;
	}

	void Beneficio::mostrarInventario() const {
		std::cout << "\n===== INVENTARIO =====\n";
		for (int i = 0; i < cantidad; i++) {
			std::cout << i + 1 << ". " << lotes[i]->toString() << std::endl;
		}
	}

	double Beneficio::valorTotalInventario() const {
		double total = 0.0;
		for (int i = 0; i < cantidad; i++) {
			total += lotes[i]->calcularValorTotal();
		}
		return total;
	}

	LoteCafe* Beneficio::loteMayorCalidad() const {
		if (cantidad == 0) {
			return nullptr;
		}

		LoteCafe* mejor = lotes[0];

		for (int i = 1; i < cantidad; i++) {
			if (lotes[i]->calcularPuntajeCalidad() > mejor->calcularPuntajeCalidad()) {
				mejor = lotes[i];
			}
		}

		return mejor;
	}

	double Beneficio::promedioCalidadPorProceso(const std::string& proceso) const {
		double suma = 0.0;
		int contador = 0;

		for (int i = 0; i < cantidad; i++) {
			if (lotes[i]->getProceso() == proceso) {
				suma += lotes[i]->calcularPuntajeCalidad();
				contador++;
			}
		}

		if (contador == 0) {
			return 0.0;
		}

		return suma / contador;
	}

	int Beneficio::contarPorProceso(const std::string& proceso) const {
		int contador = 0;

		for (int i = 0; i < cantidad; i++) {
			if (lotes[i]->getProceso() == proceso) {
				contador++;
			}
		}

		return contador;
	}

}