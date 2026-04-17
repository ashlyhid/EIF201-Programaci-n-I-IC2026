#ifndef LOTE_NATURAL_H
#define LOTE_NATURAL_H

#include "LoteCafe.h"
#include <string>

namespace EIF201 {

	class LoteNatural : public LoteCafe {
	private:
		int diasSecado;
		double humedadFinal;

	public:
		LoteNatural(const std::string& finca, double pesoKg, int altitudMsnm, int diasSecado, double humedadFinal);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		std::string getProceso() const override;
		std::string toString() const override;
	};

}

#endif