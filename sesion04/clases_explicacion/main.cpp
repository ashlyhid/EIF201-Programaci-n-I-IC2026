#include <iostream>
#include <string>
#include <iomanip>
#include <limits> //contiene constantes numericas predefinidas, asi no debemos hacerlas manualmente 
#include "Producto.h"
#include "Inventario.h"

//ctrl + d para copiar y pegar una linea de codigo
int mostrarMenu() {
	std::cout << "---- MENU ----" << std::endl;
	std::cout << "1.Agregar Producto " << std::endl;
	std::cout << "2.Buscar producto por codigo " << std::endl;
	std::cout << "3.Vender unidad de un producto " << std::endl;
	std::cout << "4.Eliminar producto " << std::endl;
	std::cout << "5.Mostrar Inventario completo" << std::endl;
	std::cout << "6.Mostrar valor total del inventario " << std::endl;
	std::cout << "7.Salir" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "Opcion: " << std::endl;
	int opcion;
	std::cin >> opcion;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return opcion;

}
int main() {

	EIF201::Inventario tienda(3);
	bool ejecutando = true;

	while (ejecutando) {

		int opcion = mostrarMenu();
		switch (opcion) {
		case 1: {
			std::string nombre, codigo;
			double precio;
			int stock;

			std::cout << "Nombre del producto: ";
			std::getline(std::cin, nombre);

			std::cout << "Codigo del producto: ";
			std::getline(std::cin, codigo);

			std::cout << "Stock del producto: ";
			std::cin >> stock;


			std::cout << "Precio del producto: ";
			std::cin >> precio;

			EIF201::Producto* nuevo = new EIF201::Producto(nombre, precio, stock, codigo);
			tienda.agregar(nuevo);
			break;
		}
		case 2: {
			std::string codigoBuscar;
			std::cout << "Ingrese el codigo del producto que desea buscar: ";
			std::getline(std::cin, codigoBuscar);

			EIF201::Producto* encontrado = tienda.buscarPorCodigo(codigoBuscar);

			if (encontrado != nullptr) {
				std::cout << "Producto encontrado!" << std::endl; //! = diferente de 
				encontrado->mostrar();
			}
			else {

			}
		}
		case 3: {
			std::string codigo;
			int cantidadVender;

			std::cout << "Digite el codigo del producto: ";
			std::cin >> codigo;

			EIF201::Producto* encontrado = Inventario.buscarPorCodigo(codigo);

			if (encontrado == nullptr) {
				std::cout << "Producto no encontrado." << std::endl;
			}
			else {
				std::cout << "Digite la cantidad a vender: ";
				std::cin >> cantidadVender;

				if (encontrado->vender(cantidadVender)) {
					std::cout << "Venta realizada con exito." << std::endl;
				}
				else {
					std::cout << "No hay suficiente stock, intente en otro momento o comuniquese con algun encargado" << std::endl;
				}
			}
		}
		case 4: {
			std::string codigo;
			std::cout << "Digite el codigo del producto a eliminar: ";
			std::cin >> codigo;

			if (!Inventario.eliminar(codigo)) {
				std::cout << "No se pudo eliminar el producto" << std::endl;
			}
			break;
		}
		case 5: {
			Inventario.mostrarTodos();
			break;
		}
		case 6: {
			std::cout << "Valor total del inventario: " << Inventario.calcularValorTotal() << std::endl;
			break;
		}
		case 7: {
			std::cout << "Saliendo del programa. Gracias por preferirnos!\n";
			exit(0);
			break;
		}
		default:
			std::cout << "Opcion invalida." << std::endl;
			break;
		}
	}