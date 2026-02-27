#include "Matriz.h"
#include <iostream>

using namespace std;

int main() {
    int matriz[FILAS][COLS];

    leerMatriz(matriz);

    cout << "\nMatriz ingresada:\n";
    imprimirMatriz(matriz);

    cout << "\nSuma de cada fila:\n";
    sumarFilas(matriz);

    cout << "\nSuma de cada columna:\n";
    sumarCols(matriz);

    cout << "\nSuma de la diagonal principal:\n";
    sumarDiagonal(matriz);

    return 0;
}