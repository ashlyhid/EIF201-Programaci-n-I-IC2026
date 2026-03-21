#include "flota.h"
#include "vehicle.h"
#include <iostream>

namespace UNA {

	Flota::Flota() {
		capacidad = 3;
		cantidad = 0;
		vehiculos = new Vehicle* [capacidad];

		for (int i = 0; i < capacidad; i++) {
			vehiculos[i] = nullptr;
		}
	}

	Flota::~Flota() {
		for (int i = 0; i < cantidad; i++) {
			delete vehiculos[i];
			vehiculos[i] = nullptr;
		}

		delete[] vehiculos;
		vehiculos = nullptr;
	}

	void Flota::redimensionar() {
		int nuevaCapacidad = capacidad * 2;
		Vehicle** nuevoArreglo = new Vehicle * [nuevaCapacidad];

		for (int i = 0; i < nuevaCapacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = vehiculos[i];
		}

		delete[] vehiculos;
		vehiculos = nuevoArreglo;
		capacidad = nuevaCapacidad;
	}

	void Flota::agregar(Vehicle* nuevo) {
		if (nuevo == nullptr) {
			std::cout << "ERROR: Puntero nulo.\n";
			return;
		}

		if (buscarPorPlaca(nuevo->getPlaca()) != nullptr) {
			std::cout << "ERROR: Ya existe un vehiculo con esa placa.\n";
			delete nuevo;
			return;
		}

		if (cantidad == capacidad) {
			redimensionar();
		}

		vehiculos[cantidad] = nuevo;
		cantidad++;

		std::cout << "Vehiculo agregado al sistema correctamente!.\n";
	}

	Vehicle* Flota::buscarPorPlaca(const std::string& placa) const {
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				return vehiculos[i];
			}
		}
		return nullptr;
	}

	void Flota::mostrarPorMarca(const std::string& marca) const {
		int encontrados = 0; 

		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getMarca() == marca) {
				vehiculos[i]->mostrar();
				encontrados++;
			}
		}

		if (encontrados == 0) {
			std::cout << "No hay vehiculos registrados de la marca " << marca << ".\n";
		}
		else {
			std::cout << "Se encontraron " << encontrados << " vehiculos de la marca " << marca << "\n";
		}
	}

	bool Flota::eliminar(const std::string& placa) {
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				if (vehiculos[i]->getActivo()) {
					std::cout << "Un vehiculo activo no puede eliminarse. Primero elimine el vehiculo e intente nuevamente.\n";
					return false;
				}
				delete vehiculos[i];

				for (int j = i; j < cantidad - 1; j++) {
					vehiculos[j] = vehiculos[j + 1];
				}

				vehiculos[cantidad - 1] = nullptr;
				cantidad--;

				std::cout << "Vehiculo eliminado con exito!.\n";
				return true;
			}
		}

		std::cout << "No se encontro ningun vehiculo con esa placa.\n";
		return false;
	}

	int Flota::contarActivos() const {
		int activos = 0;

		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getActivo()) {
				activos++;
			}
		}
		return activos;
	}

	void Flota::mostrarTodos() const {
		if (cantidad == 0) {
			std::cout << "La flota se encuentra vacia.\n";
			return;
		}
		for (int i = 0; i < cantidad; i++) {
			vehiculos[i]->mostrar();
		}
	}

}