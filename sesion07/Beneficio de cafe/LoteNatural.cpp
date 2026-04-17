#include "LoteNatural.h"
#include <sstream>

namespace EIF201 {

	LoteNatural::LoteNatural(const std::string& finca, double pesoKg, int altitudMsnm, int diasSecado, double humedadFinal)
		: LoteCafe(finca, pesoKg, altitudMsnm), diasSecado(diasSecado), humedadFinal(humedadFinal) {
	}

	double LoteNatural::calcularPuntajeCalidad() const {
		double puntaje = puntajeBaseAltitud();

		if (diasSecado >= 18 && diasSecado <= 25) {
			puntaje += 5.0;
		}
		else if (diasSecado < 18) {
			puntaje -= 6.0;
		}
		else {
			puntaje -= (diasSecado - 25) * 0.8;
		}

		if (humedadFinal >= 10.0 && humedadFinal <= 12.0) {
			puntaje += 3.0;
		}
		else if (humedadFinal < 10.0) {
			puntaje -= (10.0 - humedadFinal);
		}
		else {
			puntaje -= (humedadFinal - 12.0);
		}

		return puntaje;
	}

	double LoteNatural::calcularPrecioPorKg() const {
		double precio = 3600.0 * (calcularPuntajeCalidad() / 100.0);

		if (calcularPuntajeCalidad() > 90.0) {
			precio *= 1.20;
		}

		return precio;
	}

	std::string LoteNatural::getProceso() const {
		return "Natural";
	}

	std::string LoteNatural::toString() const {
		std::ostringstream oss;
		oss << LoteCafe::toString()
			<< " | Dias secado: " << diasSecado
			<< " | Humedad: " << humedadFinal << "%";

		if (diasSecado < 18) {
			oss << " [RIESGO MOHO]";
		}
		else if (diasSecado > 25) {
			oss << " [SOBRE-SECADO]";
		}
		else {
			oss << " [SECADO OPTIMO]";
		}

		if (humedadFinal >= 10.0 && humedadFinal <= 12.0) {
			oss << " [HUMEDAD IDEAL]";
		}
		else {
			oss << " [HUMEDAD FUERA DE RANGO]";
		}

		if (calcularPuntajeCalidad() > 90.0) {
			oss << " [ESPECIALIDAD]";
		}

		return oss.str();
	}

}