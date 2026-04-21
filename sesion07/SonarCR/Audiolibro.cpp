#include "Audiolibro.h"

namespace EIF201 {
	Audiolibro::Audiolibro(const std::string& tittle, int durationSeconds, int chapters, double price, int units)
		: Contenido(tittle, durationSeconds), chapters(chapters), price(price), units(units) {
	}

	double Audiolibro::calcularRegalias() const {
		double tasa = (durationSeconds > 3600) ? 0.30 : 0.25;
		double total = price * tasa * units;

		if (units > 1000) {
			total *= 1.12;
		}
		if (chapters > 20) {
			total *= 1.08;
		}
		return total;
	}

	std::string Audiolibro::getType() const {
		return "Audiolibro";
	}
	int Audiolibro::getPopularity() const {
		return units / 100;
	}
}