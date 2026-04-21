#ifndef CANCION_H
#define CANCION_H

#include "Contenido.h"
#include <string>

namespace EIF201 {

    class Cancion : public Contenido {
    private:
        std::string gender;
        int reproductions;

        double multiplier() const;

    public:
        Cancion(const std::string& tittle, int durationSeconds,
            const std::string& gender, int reproductions);

        double calcularRegalias() const override;
        std::string getType() const override;
        int getPopularity() const override;
    };

}

#endif