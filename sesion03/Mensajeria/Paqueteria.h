#ifndef PAQUETERIA_H
#define PAQUETERIA_H

double* crearRegistro(int& cantidad);

void ingresarPesos(double* pesos, int cantidad);

double calcularPesoTotal(const double* pesos, int cantidad);

int contarSobreLimite(const double* pesos, int cantidad, double limite);

const double* buscarMasPesado(const double* pesos, int cantidad);

#endif 

