#ifndef CONTENIDO_H
#define CONTENIDO_H
#include <string>

namespace EIF201 {

	class Contenido {
	protected:
		std::string tittle;
		int durationSeconds;

	public:
		Contenido(const std::string& tittle, int durationSeconds);

		virtual ~Contenido();
		virtual double calcularRegalias() const = 0;
		virtual std::string getType() const = 0;
		virtual int getPopularity() const = 0;

		std::string getTittle() const;
		int getDurationSeconds() const;
	};
}

#endif