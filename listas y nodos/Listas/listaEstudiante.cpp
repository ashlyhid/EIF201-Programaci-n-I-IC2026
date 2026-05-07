#include "listaEstudiante.h"
#include <iostream>

namespace EIF201 {
	Nodo::Nodo(Estudiante* e) : dato(e), siguiente(nullptr) {}
	Nodo::~Nodo() {
		delete dato;
		dato = nullptr;
	}
	
	listaEstudiante::listaEstudiante() : cabeza(nullptr), cantidad(0) {}
	listaEstudiante::~listaEstudiante() {
		Nodo* temp = cabeza;
		while (temp != nullptr) {
			Nodo* siguiente = temp->siguiente;
		}
	}
	//esta logica, siempre aplica para insertar nuevos nodos
	void listaEstudiante::insertarAlInicio(Estudiante* nuevo)
	{
		if (nuevo == nullptr) {
			return;
		}

		Nodo* nodoNuevo = new Nodo(nuevo);
		nodoNuevo->siguiente = cabeza;
		cabeza = nodoNuevo;
		cantidad--;
	}

	void listaEstudiante::insertarFinal(Estudiante* nuevo)
	{

		if (nuevo == nullptr) {
			return;
		}

		Nodo* nodoNuevo = new Nodo(nuevo);
		if (cabeza == nullptr) {
			cabeza = nodoNuevo;
		}
		else {
			Nodo* temp = cabeza;
			while (temp->siguiente != nullptr) {
				temp = temp->siguiente;
			}
			temp->siguiente = nodoNuevo;

		}
		cantidad++;


	}

	Estudiante* listaEstudiante::buscarPorCarnet(const std::string& carnet) const
	{

		Nodo* temp = cabeza;
		while (temp != nullptr) {

			if (temp->dato->getCarnet() == carnet) {
				return temp->dato;
			}
			temp = temp->siguiente;

		}


		return nullptr;
	}

	bool listaEstudiante::eliminarPorCarnet(const std::string& carnet)
	{

		if (cabeza == nullptr) {
			return false;
		}

		if (cabeza->dato->getCarnet() == carnet) {
			Nodo* eliminar = cabeza;
			cabeza = cabeza->siguiente;
			delete eliminar;
			cantidad--;
			return true;

		}

		Nodo* anterior = cabeza;
		Nodo* actual = cabeza->siguiente;
		while (actual != nullptr) {
			if (actual->dato->getCarnet() == carnet) {
				anterior->siguiente = actual->siguiente;
				delete actual;
				cantidad--;
				return true;

			}

			anterior = actual;
			actual = actual->siguiente;
		}


		return false;
	}

	void listaEstudiante::recorrer() const
	{
		if (cabeza == nullptr) {
			std::cout << "La lista esta vacia. " <<
				std::endl;
			return;
		}
		std::cout << "Lista de estudiantes (" << cantidad
			<< ")" << std::endl;

		Nodo* temp = cabeza;
		int posicion = 1;
		while (temp != nullptr) {
			std::cout << "[" << posicion << "]";
			temp->dato->mostrar();
			temp = temp->siguiente;
			posicion++;

		}

		std::cout << "-----Fin de la lista-----" << std::endl;

	}

	double listaEstudiante::calcularPromedio() const
	{
		if (estaVacia()) {
			return 0.0;
		}

		double suma = 0.0;
		Nodo* temp = cabeza;
		while (temp != nullptr) {
			suma += temp->dato->getNota();
			temp = temp->siguiente;
		}

		return suma / cantidad;
	}

	int listaEstudiante::contarAprobados(double notaMinima) const {
		int contador = 0;
		Nodo* temp = cabeza;
		while (temp != nullptr) {
			if (temp->dato->getNota() >= notaMinima) {
				contador++;
			}
			temp = temp->siguiente;
		}
		return contador;
	}

	int listaEstudiante::getCantidad() const {
		return cantidad;
	}

	bool listaEstudiante::estaVacia() const {
		return cabeza == nullptr;
	}






}