#ifndef BENEFICIO_H
#define BENEFICIO_H

#include "LoteCafe.h"
#include <string>

namespace EIF201 {

	class Beneficio {
	private:
		LoteCafe** lotes;
		int capacidad;
		int cantidad;

		void redimensionar();

	public:
		Beneficio();
		~Beneficio();

		void agregarLote(LoteCafe* lote);
		void mostrarInventario() const;
		double valorTotalInventario() const;
		LoteCafe* loteMayorCalidad() const;
		double promedioCalidadPorProceso(const std::string& proceso) const;
		int contarPorProceso(const std::string& proceso) const;
	};

}

#endif