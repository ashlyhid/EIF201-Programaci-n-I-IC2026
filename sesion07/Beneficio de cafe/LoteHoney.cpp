#include "LoteHoney.h"
#include <sstream>

namespace EIF201 {

	LoteHoney::LoteHoney(const std::string& finca, double pesoKg, int altitudMsnm, double porcentajeMucilago)
		: LoteCafe(finca, pesoKg, altitudMsnm), porcentajeMucilago(porcentajeMucilago) {
	}

	double LoteHoney::calcularPuntajeCalidad() const {
		double puntaje = puntajeBaseAltitud();

		puntaje += porcentajeMucilago * 0.08;

		if (altitudMsnm > 1200 && porcentajeMucilago > 60.0) {
			puntaje += 2.5;
		}

		return puntaje;
	}

	double LoteHoney::calcularPrecioPorKg() const {
		double precio = 3200.0;

		if (porcentajeMucilago >= 75.0) {
			precio *= 1.15;
		}

		return precio * (calcularPuntajeCalidad() / 100.0);
	}

	std::string LoteHoney::getProceso() const {
		return "Honey";
	}

	std::string LoteHoney::toString() const {
		std::ostringstream oss;
		std::string subtipo;

		if (porcentajeMucilago < 25.0) {
			subtipo = "White";
		}
		else if (porcentajeMucilago < 50.0) {
			subtipo = "Yellow";
		}
		else if (porcentajeMucilago < 75.0) {
			subtipo = "Red";
		}
		else {
			subtipo = "Black";
		}

		oss << LoteCafe::toString()
			<< " | Mucilago: " << porcentajeMucilago << "%"
			<< " | Subtipo: " << subtipo;

		if (altitudMsnm > 1200 && porcentajeMucilago > 60.0) {
			oss << " [BONUS SINERGICO]";
		}

		if (subtipo == "Black") {
			oss << " [BLACK HONEY]";
		}

		return oss.str();
	}

}