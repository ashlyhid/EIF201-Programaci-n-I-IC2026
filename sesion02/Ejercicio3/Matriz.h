#ifndef MATRIZ_H
#define MATRIZ_H

const int FILAS = 3;
const int COLS = 3;

void leerMatriz(int matriz[FILAS][COLS]);
void imprimirMatriz(int matriz[FILAS][COLS]);
void sumarFilas(int matris[FILAS][COLS]);
void sumarCols(int matriz[FILAS][COLS]);
void sumarDiagonal(int matriz[FILAS][COLS]);

#endif 
