#include <iostream>
#include "Cancion.h"
#include "Podcast.h"
#include "Audiolibro.h"
#include "Plataforma.h"

int main() {
    EIF201::Plataforma p;

    p.add(new EIF201::Cancion("Come as you are", 300, "rock", 2000));
    p.add(new EIF201::Cancion("Please Please Please", 200, "pop", 5000));
    p.add(new EIF201::Podcast("Historias del Buho", 800, 60, true, 5000));
    p.add(new EIF201::Podcast("The Wild Project", 143, 369, true, 120));
    p.add(new EIF201::Audiolibro("Harry Potter", 2951, 11, 190, 210));

    p.show();

    std::cout << "Total regalias: " << p.totalRegalias() << std::endl;

    return 0;
}