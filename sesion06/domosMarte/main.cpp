#include <iostream>
#include "Colonia.h"

using namespace EIF201;

int main() {
    Colono* c1 = new Colono(1, "Ana", Biologo, 10, 80);
    Colono* c2 = new Colono(2, "Luis", Ingeniero, 15, 70);
    Colono* c3 = new Colono(3, "Marta", Medico, 12, 90);
    Colono* c4 = new Colono(4, "Diego", Piloto, 14, 65);
    Colono* c5 = new Colono(5, "Elena", Geologo, 11, 85);
    Colono* c6 = new Colono(6, "Sofia", Ingeniero, 16, 75);
    Colono* c7 = new Colono(7, "Carlos", Biologo, 13, 78);
    Colono* c8 = new Colono(8, "Julia", Piloto, 18, 88);

    Colonia colonia("Ares Prime", "Marte", 3);

    colonia.configurarDomo(0, 101, Laboratorio, 40, 3);
    colonia.configurarDomo(1, 102, Ingenieria, 45, 3);
    colonia.configurarDomo(2, 103, Habitat, 60, 4);

    Colono* lista[8] = { c1, c2, c3, c4, c5, c6, c7, c8 };

    std::cout << "=== ASIGNACION INTELIGENTE ===\n";
    for (int i = 0; i < 8; i++) {
        if (colonia.asignarInteligente(lista[i])) {
            std::cout << "Asignado: " << lista[i]->getName() << std::endl;
        }
        else {
            std::cout << "No se pudo asignar: " << lista[i]->getName() << std::endl;
        }
    }

    colonia.tableroControl();
    colonia.alertOxigeno(1.2);

    std::cout << "\n=== TRANSFERENCIA INCOMPATIBLE ===\n";
    if (!colonia.transferirColono(1, 101, 102)) {
        std::cout << "Fallo correcto: colono incompatible o sin condiciones.\n";
    }

    std::cout << "\n=== TRANSFERENCIA COMPATIBLE ===\n";
    if (colonia.transferirColono(2, 102, 103)) {
        std::cout << "Transferencia realizada.\n";
    }
    else {
        std::cout << "No se pudo transferir.\n";
    }

    colonia.tableroControl();

    std::cout << "\n=== EVACUACION DOMO 101 ===\n";
    int noReubicados = colonia.evacuarDomo(101);
    std::cout << "No reubicados: " << noReubicados << std::endl;

    colonia.tableroControl();

    std::cout << "\n=== REBALANCEO ===\n";
    int movidos = colonia.rebalancear();
    std::cout << "Colonos rebalanceados: " << movidos << std::endl;

    colonia.tableroControl();

    std::cout << "\n=== PRODUCTIVIDAD BIOLOGOS ===\n";
    std::cout << colonia.productividadPorEspe(Biologo) << std::endl;

    colonia.globalStats();

    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;

    return 0;
}