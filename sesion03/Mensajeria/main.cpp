#include <iostream>
#include <iomanip>
#include "Paqueteria.h"

int main() {
	int cantidad = 0;
	double* pesos = crearRegistro(cantidad);
	ingresarPesos(pesos, cantidad);

	double total = calcularPesoTotal(pesos, cantidad);
	double promedio = total / cantidad;

	double limite;	
	std::cout << "Ingrese el limite de peso peermitido: ";
	std::cin >> limite;

	int sobreLimite = contarSobreLimite(pesos, cantidad, limite);
	const double* masPesado = buscarMasPesado(pesos, cantidad);

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\n --- RESULTADOS ---\n";
	std::cout << "Peso total: " << total << " kg\n";	
	std::cout << "Peso promedio: " << promedio << "kg\n";
	std::cout << "Paquetes sobre el limite de peso de " << limite << " kg: " << sobreLimite << "\n";
	std::cout << "Paquete mas pesado: " << *masPesado << " kg\n";

	delete[] pesos;
	pesos = nullptr;
	
	return 0;


}