#include "Contenido.h"

namespace EIF201 {

    Contenido::Contenido(const std::string& tittle, int durationSeconds)
        : tittle(tittle), durationSeconds(durationSeconds) {
    }

    Contenido::~Contenido() {
    }

    std::string Contenido::getTittle() const {
        return tittle;
    }

    int Contenido::getDurationSeconds() const {
        return durationSeconds;
    }

}