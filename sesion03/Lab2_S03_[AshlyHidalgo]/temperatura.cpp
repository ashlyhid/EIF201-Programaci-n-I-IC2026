#include "temperatura.h"
#include <iostream>
#include <iomanip>

double* crearRegistro(int& cantidadDias) {
	std::cout << "+--------------------------------------+" << std::endl;
	std::cout << "| Sistema de Registro de Temperaturas |" << std::endl;
	std::cout << "+--------------------------------------+" << std::endl;
	std::cout << "Ingrese la cantidad de dias a registrar: ";
	std::cin >> cantidadDias;
	while (cantidadDias <= 0) {
		std::cout << "ERROR: debe de ser mayor a cero, intente de nuevo: ";
		std::cin >> cantidadDias;
	}
	double* registro = new double[cantidadDias];
	return registro;
}

void ingresarTemperaturas(double* registro, int cantidad) {
	std::cout << std::endl << "Ingrese las temperaturas en grados Celsius: " << std::endl;
	for (int i = 0; i < cantidad; i++) {
		std::cout << " Dia " << (i + 1) << ": ";
		std::cin >> registro[i];
	}
}

double calcularPromedio(const double* registro, int cantidad) {
	double suma = 0.0;
	for (int i = 0; i < cantidad; i++) {
		suma += registro[i];
	}
	return suma / cantidad;
}

double calcularMaximo(const double* registro, int cantidad) {
	double maximo = registro[0];
	for (int i = 0; i < cantidad; i++) {
		if (registro[i] > maximo) {
			maximo = registro[i];
		}
	}
	return maximo;
}

double CalcularMinimo(const double* registro, int cantidad) {
	double minimo = registro[0];
	for (int i = 0; i < cantidad; i++) {
		if (registro[i] < minimo) {
			minimo = registro[i];
		}
	}
	return minimo;
}

void mostrarResultados(const double* registro, int cantidad) {
	std::cout << std::endl << std::fixed << std::setprecision(2);
	std::cout << "+--------------------------------------+" << std::endl;
	std::cout << "|         RESUMEN DEL REGISTRO         |" << std::endl;
	std::cout << "+--------------------------------------+" << std::endl;
	std::cout << "Dias registrados: " << cantidad << std::endl;
	std::cout << "Temperatura Promedio: " << calcularPromedio(registro, cantidad) << "C°" << std::endl;
	std::cout << "Temperatura Maxima: " << calcularMaximo(registro, cantidad) << "C°" << std::endl;
	std::cout << "Temperatura Minima: " << CalcularMinimo(registro, cantidad) << "C°" << std::endl;
	std::cout << "+--------------------------------------+" << std::endl;
}