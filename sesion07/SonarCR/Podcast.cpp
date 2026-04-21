#include "Podcast.h"
namespace EIF201 {
	Podcast::Podcast(const std::string& title, int durationSeconds, int episodes, bool patrocinio, int promOyentes)
		: Contenido(title, durationSeconds), episodes(episodes), patrocinio(patrocinio), promOyentes(promOyentes) {
	}

	double Podcast::calcularRegalias() const {
		double base = episodes * 1500 * (promOyentes / 1000.0);

		if (patrocinio) {
			base *= 1.45;
		}
		if (episodes > 50) {
			base *= 1.18;
		}
		if (durationSeconds < 900) {
			base *= 0.80;
		}

		return base;
	}

	std::string Podcast::getType() const {
		return "Podcast";
	}

	int Podcast::getPopularity() const {
		return promOyentes / 1000;
	}
}
