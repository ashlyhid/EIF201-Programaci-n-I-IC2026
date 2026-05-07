#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

namespace EIF201 {

	class Estudiante
	{

	private:
		std::string nombre;
		std::string carnet;
		double nota;

	public:
		Estudiante(const std::string& nombre, const std::string& carnet, double nota);
		~Estudiante();

		std::string getNombre()const;
		std::string getCarnet()const;
		void setNota(double nota);
		double getNota()const;
		void mostrar()const;



	};



}


#endif