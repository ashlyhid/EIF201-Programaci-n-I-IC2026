#ifndef ARQUERO_H
#define ARQUERO_H

#include "Criaturas.h"

namespace EIF201 {
	class Arquero : public Criaturas { //si el override falla, es por culpa de esto que estaria mal escrito
	private:
		double destreza;
		int flechas;
		int flechasMax;

	public:
		Arquero(const std::string& nombre, int nivel, double puntosVida, double destreza, int flechas)
			: Criaturas(nombre, nivel, puntosVida), destreza(destreza), flechas(flechas), flechasMax(flechas) {
		}

		~Arquero() override;

		double calcularAtaque() override;
		std::string getTipo() const override;
		bool puedeAtacar() const override;
		std::string toString() const override;

		int getFlechas() const;

	};
}

#endif 
