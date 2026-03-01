#include "Nombre.h"
#include <cctype>

string primerNombre(const string& nombreCompleto) {
	int pos = nombreCompleto.find(' ');
	return nombreCompleto.substr(0, pos);	
}

string primerApellido(const string& nombreCompleto) {
	int primerEspacio = nombreCompleto.find(' ');
	int segundoEspacio = nombreCompleto.find(' ', primerEspacio + 1);

	return nombreCompleto.substr(primerEspacio + 1, segundoEspacio - primerEspacio - 1);
}

string segundoApellido(const string& nombreCompleto) {
	int segundoEspacio = nombreCompleto.find(' ', nombreCompleto.find(' ') + 1);

	return nombreCompleto.substr(segundoEspacio + 1);
}

int vocales(const string& nombreCompleto) {
	int contador = 0;
	for (char c : nombreCompleto) {
		c = tolower(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			contador++;
		}
	}
	return contador;
}

string convertirMayus(const string& nombreCompleto) {
	string resultado = nombreCompleto;
	for(char& c : resultado) {
		c = toupper(c);
	}
	return resultado;
}

int longitudNombre(const string& nombreCompleto) {
	return nombreCompleto.length();
}