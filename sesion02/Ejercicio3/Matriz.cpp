#include <iostream>
#include <iomanip>
#include "Matriz.h"

using namespace std;

void leerMatriz(int matriz[FILAS][COLS]) {
    cout << "Ingrese los 9 valores enteros de la matriz 3x3:\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {

            cout << setw(6) << matriz[i][j];
        }
        cout << endl;
    }
}

void sumarFilas(int matriz[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        int suma = 0;
        for (int j = 0; j < COLS; j++) {
            suma += matriz[i][j];
        }
        cout << "Fila " << (i + 1) << ": " << suma << endl;
    }
}

void sumarCols(int matriz[FILAS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        int suma = 0;
        for (int i = 0; i < FILAS; i++) {
            suma += matriz[i][j];
        }
        cout << "Columna " << (j + 1) << ": " << suma << endl;
    }
}

void sumarDiagonal(int matriz[FILAS][COLS]) {
    int suma = 0;
    for (int i = 0; i < FILAS; i++) {
        suma += matriz[i][i];
    }
    cout << "Diagonal principal: " << suma << endl;
}