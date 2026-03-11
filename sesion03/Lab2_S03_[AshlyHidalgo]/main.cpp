#include <iostream>
#include "temperatura.h"

int main() {
	int cantidadDias = 0;
	double* registroTemp = crearRegistro(cantidadDias);
	ingresarTemperaturas(registroTemp, cantidadDias);
	mostrarResultados(registroTemp, cantidadDias);

	delete[] registroTemp;
	registroTemp = nullptr;

	return 0;
}