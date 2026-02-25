#include "Parametros.h"


int mayor(int arr[]) {
	int max = arr[0];
	for (int i = 1; i < tam; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int menor(int arr[]) {
	int min = arr[0];
	for (int j = 1; j < tam; j++) {
		if (arr[j] < min) {
			min = arr[j];
		}
	}
	return min;
}
int suma(int arr[]) {
	int total = 0;
	for (int i = 0; i < tam; i++) {
		total += arr[i];
	}
	return total;
}

double promedio(int arr[]) {
	return static_cast<double>(suma(arr)) / tam;
}
