#ifndef CRIATURAS_H
#define CRIATURAS_H
#include<string>
#include<iostream>
#include<sstream>

namespace EIF201{

	class Criaturas
	{
	protected:
		std::string nombre;
		int nivel;
		double puntosVida;
		double puntosVidaMax;


	public:
		Criaturas(const std::string nombre, int nivel, double puntosVida)
			: nombre(nombre), nivel(nivel), puntosVida(puntosVida), puntosVidaMax(puntosVidaMax)
		{
		}
		virtual ~Criaturas() {}
		virtual double calcularAtaque() = 0;
		virtual std::string getTipo() const = 0;
		virtual bool puedeAtacar() const = 0;
		virtual std::string toString() const {

			std::ostringstream oss;
			oss << getTipo() << "|" << nombre << "|" << "nv" <<
				nivel << "l" << "hp: " << puntosVida << "/" << puntosVidaMax;
			return oss.str();
		}
		void recibirDanno(double danno) {
			if (danno > 0) {
				puntosVida -= danno;
				if (puntosVida < 0) {
					puntosVida = 0;
				}
			}
		}

		bool estaVivo() const {
			return puntosVida > 0;
		}
		std::string getNombre() const {
			return nombre;
		}
		int getNivel() const {
			return nivel;
		}
		double getPuntosVida() const {
			return puntosVida;
		}
		double getPuntosVidaMax() const {
			return puntosVidaMax;
		}

	};
}
#endif