#ifndef PODCAST_H
#define PODCAST_H

#include "Contenido.h"
#include <string>

namespace EIF201 {

    class Podcast : public Contenido {
    private:
        int episodes;
        bool patrocinio;
        int promOyentes;

    public:
        Podcast(const std::string& title, int durationSeconds,
            int episodes, bool patrocinio, int promOyentes);

        double calcularRegalias() const override;
        std::string getType() const override;
        int getPopularity() const override;
    };

}

#endif