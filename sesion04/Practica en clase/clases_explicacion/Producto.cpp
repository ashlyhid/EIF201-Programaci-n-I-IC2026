#include "Producto.h"
#include <iomanip>

namespace EIF201 {

	Producto::Producto(std::string nombre, double precio, int stock, std::string codigo)
		: nombre(nombre), precio(precio), stock(stock), codigo(codigo) {
	}
	//Getters
	std::string Producto::getNombre() const {
		return nombre;
	}

	double Producto::getPrecio() const {
		return precio;
	}
	int Producto::getStock() const {
		return stock;
	}

	std::string Producto::getCodigo() const {
		return codigo;
	}

	//setters

	void Producto::setPrecio(double nuevoPrecio) {
		if (nuevoPrecio <= 0) { //error first. Para evitar sobrepoblacion de else 

			std::cout << "Error. el precio no puede ser negativo";

		}
		precio = nuevoPrecio;
	}

	void Producto::setStock(int nuevaCantidad) {
		if (nuevaCantidad < 0) { //error first.
			std::cout << "Error. el stock no puede ser negativa" << std::endl;
		}
		stock = nuevaCantidad;
	}
	void Producto::mostrar() const {

		std::cout << " [" << codigo << "] " << nombre
			<< "|Precio: $" << std::fixed << std::setprecision(2) << precio
			<< "|Stock: " << stock << " unidades" << std::endl;
	}

	bool Producto::vender(int cantidad) { //vender hecho a base de lo poco que entiendo booleanos 
		if (cantidad <= stock) {
			stock -= cantidad;
			return true;
		}
		return false;

	}


}