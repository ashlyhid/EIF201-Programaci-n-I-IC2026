#include "LoteLavado.h"
#include <sstream>

namespace EIF201 {

	LoteLavado::LoteLavado(const std::string& finca, double pesoKg, int altitudMsnm, int horasFermentacion)
		: LoteCafe(finca, pesoKg, altitudMsnm), horasFermentacion(horasFermentacion) {
	}

	double LoteLavado::calcularPuntajeCalidad() const {
		double puntaje = puntajeBaseAltitud();

		if (horasFermentacion >= 18 && horasFermentacion <= 36) {
			puntaje += 3.0;
		}
		else if (horasFermentacion < 18) {
			puntaje -= 4.0;
		}
		else {
			int exceso = horasFermentacion - 36;
			int bloques12 = exceso / 12;
			if (exceso % 12 != 0) {
				bloques12++;
			}
			puntaje -= 2.0 * bloques12;
		}

		return puntaje;
	}

	double LoteLavado::calcularPrecioPorKg() const {
		double precioBase = 2800.0;
		return precioBase * (calcularPuntajeCalidad() / 100.0);
	}

	std::string LoteLavado::getProceso() const {
		return "Lavado";
	}

	std::string LoteLavado::toString() const {
		std::ostringstream oss;
		oss << LoteCafe::toString()
			<< " | Fermentacion: " << horasFermentacion << " h";

		if (horasFermentacion < 18) {
			oss << " [SUB-FERMENTADO]";
		}
		else if (horasFermentacion > 36) {
			oss << " [SOBRE-FERMENTADO]";
		}
		else {
			oss << " [OPTIMO]";
		}

		return oss.str();
	}

}