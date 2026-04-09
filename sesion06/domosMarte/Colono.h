#ifndef  COLONO_H
#define COLONO_H
#include <string>

namespace EIF201 {
	enum Especiality {
		Ingeniero,
		Biologo,
		Medico,
		Geologo,
		Piloto
	};

	class Colono {
	private:
		int id;
		std::string name;
		Especiality especiality;
		double consumoOxigenoHora;
		int productividad;

	public:
		Colono(int id, std::string name, Especiality especiality, double consumoOxigeno, int productividad);
		int getId() const;
		std::string getName() const;
		Especiality getEspeciality() const;
		double getConsumoOxigeno() const;
		int getProductividad() const;

		std::string especialityToString() const;
		void mostrar() const;
	};
}
#endif 
