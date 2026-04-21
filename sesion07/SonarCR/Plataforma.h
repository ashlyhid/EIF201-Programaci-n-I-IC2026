#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Contenido.h"

namespace EIF201 {
	class Plataforma {
	private:
		Contenido** lista;
		int capacity;
		int cantidad;

		void redimensionar();

	public:
		Plataforma();
		~Plataforma();

		void add(Contenido* contenido);
		void show() const;
		double totalRegalias() const;
	};
}

#endif 