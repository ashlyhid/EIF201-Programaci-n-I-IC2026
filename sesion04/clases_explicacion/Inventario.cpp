#include "Inventario.h"
#include <iomanip>

namespace EIF201 {
	Inventario::Inventario(int cantidadInicial) : cantidad(0), capacidad(cantidadInicial) {
		productos = new Producto * [cantidadInicial];
		for (int i = 0; i < capacidad; i++) {
			productos[i] = nullptr;
		}
	}
	Inventario::~Inventario() {
		for (int i = 0; i < cantidad; i++) {
			delete productos[i];
			productos[i] = nullptr;
		}

		delete[] productos;
		productos = nullptr;
		std::cout << "Inventario destruido";
	}

	void Inventario::redimensionar() {
		int nuevaCapacidad = capacidad * 2;	
		Producto** nuevoArreglo = new Producto * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = productos[i];
		}
		//inicializar las posiciones nuevas
		for (int i = cantidad; i < nuevaCapacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] productos;

		productos = nuevoArreglo;
		capacidad = nuevaCapacidad;
	}

	void Inventario::agregar(Producto* nuevo) {
		if (nuevo == nullptr) {
			std::cout << "ERROR";
			return;
		}
		if (cantidad == capacidad) {
			redimensionar();
		}
		productos[cantidad] = nuevo;
		cantidad++; //como el conteo es manual, cantidad lo va contando y lo acopla
	}

	void Inventario::mostrarTodos() const {
		if (cantidad == 0) {
			std::cout << "ERROR, no data" << std::endl;
			return;
		}
		std::cout << "---------- INVENTARIO ----------" << std::endl;
		for (int i = 0; i << cantidad; i++) {
			productos[i]->mostrar(); // -> significa acceso directo
		}
		std::cout << "------------------------------" << std::endl;

	}

	//BuscarPorCodigo
	Producto* Inventario::buscarPorCodigo(std::string codigo) const {
		for (int i = 0 ; i < cantidad; i++) {
			if (productos[i]->getCodigo() == codigo) {
				return productos[i];
			}
		}
		return nullptr;
	}

	bool Inventario::eliminar(std::string codigo) {
		int posicion = -1; //posicion del producto a eliminar (por conveniencia)	
		for (int i = 0; i < cantidad; i++) {
			if (productos[i]->getCodigo() == codigo) {
				posicion = i;
				break;
			}
		}
		if (posicion == -1) {
			std::cout << "ERROR, producto no encontrado" << std::endl;
			return false;
		}
		std::string nombreProducto = productos[posicion]->getNombre();
		delete productos[posicion];
		for (int i = posicion; i < cantidad - 1; i++) {
			productos[i] = productos[i + 1]; //proceso de compactacion, se va moviendo cada producto a la izquierda
		}
		productos[cantidad - 1] = nullptr;
		cantidad--; // cantidad = cantidad -1 (se le resta uno a la cantidad maxima)
		std::cout << "Producto " << nombreProducto << " eliminado del inventario";
		return true;
	}

	double Inventario::calcularValorTotal() const {
		int precio = 0;
		for (int i = precio; i < cantidad; i++) {
			if (i -= cantidad) {
				return precio * cantidad;
			}
			else {
				std::cout << "El valor total es de: " << std::endl;
			}
		}
	}

	int Inventario::getCantidad() const {
		return cantidad;
	}

	int Inventario::getCapacidad() const {
		return capacidad;
	}
}