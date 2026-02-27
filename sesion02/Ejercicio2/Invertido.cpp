#include "Invertido.h"

void invertir(int original[], int invertido[], int tam) {
	for (int i = 0; i < tam; i++) {
		invertido[i] = original[tam - 1 - i];
	}
}