#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

namespace EIF201 { //llama a todas las funciones para no volverlas a definir 
	class Producto
	{
	private:
		std::string nombre;
		double precio;
		int stock;
		std::string codigo;

	public:
		Producto(std::string nombre, double precio, int stock, std::string codigo);

		//getters

		std::string getNombre() const; //siempre se mantiene constante, solo en los setters se puede cambiar 
		double getPrecio() const;
		int getStock() const;
		std::string getCodigo() const;

		//setters
		void setPrecio(double nuevoPrecio);
		void setStock(int nuevaCantidad);

		//mostrar toda la informacion
		void mostrar() const;
		bool vender(int cantidad);
	};
}


#endif