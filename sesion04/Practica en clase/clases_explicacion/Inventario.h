#pragma once
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Producto.h"
#include <string>

namespace EIF201 {
	class Inventario {
	private:
		Producto** productos; //arreglo dinamico
		int cantidad;
		int capacidad;

		void redimensionar(); //cambia la capacidad del vector
	public:
		Inventario(int capacidadInicial = 3);

		~Inventario();
		void agregar(Producto* nuevo);
		void mostrarTodos() const;

		Producto* buscarPorCodigo(std::string codigo) const;
		bool eliminar(std::string codigo);
		double calcularValorTotal() const;

		int getCantidad() const;
		int getCapacidad() const;
	};
}
#endif