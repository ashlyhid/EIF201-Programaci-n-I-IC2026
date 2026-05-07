#include "Estudiante.h"
#include <iostream>
#include <iomanip>

namespace EIF201 {

	Estudiante::Estudiante(const std::string& nombre, const std::string& carnet, double nota) :nombre(nombre), carnet(carnet), nota(nota)
	{

	}
	Estudiante::~Estudiante() {}

	std::string Estudiante::getNombre() const
	{
		return nombre;
	}

	std::string Estudiante::getCarnet() const
	{
		return carnet;
	}

	void Estudiante::setNota(double nota)
	{
		this->nota = nota;
	}

	double Estudiante::getNota() const
	{
		return nota;
	}

	void Estudiante::mostrar() const
	{

		std::cout << " Carnet: " << carnet
			<< "Nombre: " << nombre
			<< " Nota: " << std::fixed << std::setprecision(1)
			<< nota << std::endl;

	}


}