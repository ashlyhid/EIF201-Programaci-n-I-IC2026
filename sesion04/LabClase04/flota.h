#ifndef	FLOTA_H
#define FLOTA_H

#include "vehicle.h"
#include <string>

namespace UNA {

	class Flota {
	private:
		Vehicle** vehiculos;
		int cantidad;
		int capacidad;
		void redimensionar();

	public:
		Flota();
		~Flota();

		void agregar(Vehicle* nuevo);
		Vehicle* buscarPorPlaca(const std::string& placa) const;
		void mostrarPorMarca(const std::string& marca) const;
		bool eliminar(const std::string& placa);
		int contarActivos() const;
		void mostrarTodos() const;
	};
}



#endif