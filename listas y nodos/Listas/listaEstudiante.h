#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H
#include "Estudiante.h"


namespace EIF201 {


	struct Nodo {
		Estudiante* dato;
		Nodo* siguiente;


		Nodo(Estudiante* e);
		~Nodo();

	};


	class listaEstudiante
	{

	private:
		Nodo* cabeza;
		int cantidad;

	public:

		listaEstudiante();
		~listaEstudiante();


		void insertarAlInicio(Estudiante* nuevo);
		void insertarFinal(Estudiante* nuevo);

		Estudiante* buscarPorCarnet(const std::string& carnet)const;

		bool eliminarPorCarnet(const std::string& carnet);

		void recorrer()const;

		double calcularPromedio()const;

		int contarAprobados(double notaMinima)const;

		int getCantidad()const;
		bool estaVacia()const;




	};


}


#endif