#ifndef LOTE_LAVADO_H
#define LOTE_LAVADO_H

#include "LoteCafe.h"
#include <string>

namespace EIF201 {

	class LoteLavado : public LoteCafe {
	private:
		int horasFermentacion;

	public:
		LoteLavado(const std::string& finca, double pesoKg, int altitudMsnm, int horasFermentacion);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		std::string getProceso() const override;
		std::string toString() const override;
	};

}

#endif