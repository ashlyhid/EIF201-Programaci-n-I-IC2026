#ifndef LOTECAFE_H
#define LOTECAFE_H

#include <string>

namespace EIF201 {

	class LoteCafe {
	protected:
		std::string finca;
		double pesoKg;
		int altitudMsnm;

		double puntajeBaseAltitud() const;

	public:
		LoteCafe(const std::string& finca, double pesoKg, int altitudMsnm);
		virtual ~LoteCafe();

		virtual double calcularPuntajeCalidad() const = 0;
		virtual double calcularPrecioPorKg() const = 0;
		virtual std::string getProceso() const = 0;

		double calcularValorTotal() const;
		virtual std::string toString() const;

		std::string getFinca() const;
		double getPesoKg() const;
		int getAltitudMsnm() const;
	};

}

#endif