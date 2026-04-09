#ifndef DOMO_H
#define DOMO_H

#include <string>
#include "Colono.h"

namespace EIF201 {
	enum typeDomo {
		Laboratorio, 
		Ingenieria,
		Habitat
	};

	class Domo {
	private: 
		int codigo;
		typeDomo type;
		double capacidadOxigeno;
		int maxOcupantes;
		bool sellado;
		Colono** colonos;
		int cantidadColonos;	

	public: 
		Domo(int codigo, typeDomo type, double capacidadOxigeno, int maxOcupantes);
		~Domo();

		int getCodigo() const;
		typeDomo getType() const;
		double getCapacidadOxigeno() const;
		int getMaxOcupantes() const;
		int getCantidadColonos() const;
		bool isSellado() const;

		std::string typeToString() const;
		bool esCompatible(const Colono* colono) const;
		bool estaLleno() const;
		double consumoActual() const;
		double ratioOxigeno() const;
		double ratioSiIngresa(const Colono* colono) const;
		bool puedeIngresar(const Colono* colono) const;

		bool addColono(Colono* colono);
		bool deleteColonoId(int id, Colono*& colonoEliminado);
		int evacuacionForzosa(Colono** destino, int maxDestino);

		void sellar();
		void abrir();

		Colono* searchColonoId(int id) const;
		void mostrar() const;
	};
}








#endif 
