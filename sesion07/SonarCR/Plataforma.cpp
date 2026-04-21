#include "Plataforma.h"
#include <iostream>

namespace EIF201 {
	Plataforma::Plataforma() {
		capacity = 8;
		cantidad = 0;
		lista = new Contenido * [capacity];
	}

	void Plataforma::redimensionar() {
		capacity *= 2;
		Contenido** nuevo = new Contenido* [capacity];

		for (int i = 0; i < cantidad; i++) {
			nuevo[i] = lista[i];
		}

		delete[] lista;
		lista = nuevo;
	}

	void Plataforma::add(Contenido* c) {
		if (cantidad == capacity) {
			redimensionar();
		}

		lista[cantidad++] = c;
	}

	void Plataforma::show() const {
		for (int i = 0; i < cantidad; i++) {
			std::cout << lista[i]->getType()
				<< " | " << lista[i]->getTittle()
				<< " |  Regalias: " << lista[i]->calcularRegalias() << std::endl;
		}
	}

	double Plataforma::totalRegalias() const {
		double total = 0;
		for (int i = 0; i < cantidad; i++) {
			total += lista[i]->calcularRegalias();
		}
		return total;
	}

	Plataforma::~Plataforma() {
		for (int i = 0; i < cantidad; i++) {
			delete lista[i];
		}
		delete[] lista;
	}
}