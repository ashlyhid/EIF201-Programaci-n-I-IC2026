#include "LoteCafe.h"
#include <sstream>

namespace EIF201 {

	LoteCafe::LoteCafe(const std::string& finca, double pesoKg, int altitudMsnm)
		: finca(finca), pesoKg(pesoKg), altitudMsnm(altitudMsnm) {
	}

	LoteCafe::~LoteCafe() {
	}

	double LoteCafe::puntajeBaseAltitud() const {
		if (altitudMsnm > 1400) {
			return 88.0;
		}
		else if (altitudMsnm >= 1201) {
			return 84.0;
		}
		else if (altitudMsnm >= 801) {
			return 80.0;
		}
		else {
			return 75.0;
		}
	}

	double LoteCafe::calcularValorTotal() const {
		return pesoKg * calcularPrecioPorKg();
	}

	std::string LoteCafe::toString() const {
		std::ostringstream oss;
		oss << "Proceso: " << getProceso()
			<< " | Finca: " << finca
			<< " | Peso: " << pesoKg << " kg"
			<< " | Altitud: " << altitudMsnm << " msnm"
			<< " | Calidad: " << calcularPuntajeCalidad()
			<< " | Precio/kg: " << calcularPrecioPorKg()
			<< " | Total: " << calcularValorTotal() << " colones";
		return oss.str();
	}

	std::string LoteCafe::getFinca() const {
		return finca;
	}

	double LoteCafe::getPesoKg() const {
		return pesoKg;
	}

	int LoteCafe::getAltitudMsnm() const {
		return altitudMsnm;
	}

}