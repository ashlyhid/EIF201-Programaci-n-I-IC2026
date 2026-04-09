#ifndef  COLONIA_H
#define COLONIA_H
#include <string>
#include "Domo.h"

namespace EIF201 {
	class Colonia {
	private:
		std::string name;
		std::string planets;

		Domo** domos;
		int cantidadDomos;

	public:
		Colonia(const std::string& name, const std::string& planets, int cantidadDomos);
		~Colonia();

		void configurarDomo(int indice, int codigo, typeDomo type, double capacidadOxigeno, int maxOcupantes);

		std::string getName() const;
		std::string getPlanets() const;
		int getCantidadDomos() const;
		Domo* getDomo(int indice) const;

		bool asignarInteligente(Colono* colono);
		bool transferirColono(int idColono,int codigoOrigen, int codigoDestino);
		int evacuarDomo(int codigoDomo);
		int rebalancear();
		
		Colono* buscarColono(int idColono, Domo*& domoEncontrado) const;

		void tableroControl() const;
		void alertOxigeno(double umbral) const;
		int productividadPorEspe(Especiality especiality) const;
		void globalStats() const;
	};
}

#endif 
