#ifndef AUDIOLIBRO_H
#define AUDIOLIBRO_H

#include "Contenido.h"
#include <string>

namespace EIF201 {

    class Audiolibro : public Contenido {
    private:
        int chapters;
        double price;
        int units;

    public:
        Audiolibro(const std::string& title, int durationSeconds,
            int chapters, double price, int units);
        double calcularRegalias() const override;
        std::string getType() const override;
        int getPopularity() const override;
    };

}

#endif