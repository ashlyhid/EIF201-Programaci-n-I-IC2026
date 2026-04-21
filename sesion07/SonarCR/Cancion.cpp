#include "Cancion.h"
namespace EIF201 {
	Cancion::Cancion(const std::string& title, int durationSeconds, const std::string& gender, int reproductions)
		:Contenido(title, durationSeconds), gender(gender), reproductions(reproductions) {
	}

	double Cancion::multiplier() const {
		if (gender == "Jazz" || gender == "Clasica") {
			return 1.4;
		}
		if (gender == "Rock" || gender == "Indie") {
			return 1.0;
		}
		if (gender == "Pop" || gender == "Electronica") {
			return 0.9;
		}
		return 0.75;
	}

	double Cancion::calcularRegalias() const {
		double base = reproductions * 3.5 * multiplier();

		if (reproductions > 1000000) {
			base *= 1.25;
		}
		else if (durationSeconds > 240) {
			base *= 1.10;
		}
		return base;
	}

	std::string Cancion::getType() const {
		return "Cancion";
	}

	int Cancion::getPopularity() const {
		return reproductions / 100000;
	}

}