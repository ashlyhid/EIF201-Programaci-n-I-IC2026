#include <iostream>
#include <iomanip>
#include "Beneficio.h"
#include "LoteLavado.h"
#include "LoteHoney.h"
#include "LoteNatural.h"

using namespace EIF201;

int main() {

    Beneficio beneficio;

    beneficio.agregarLote(new LoteLavado("Finca La Colina", 120.5, 1500, 24)); 
    beneficio.agregarLote(new LoteLavado("Finca El Roble", 95.0, 1100, 12));   
    beneficio.agregarLote(new LoteLavado("Finca Don Chico", 80.0, 1300, 50));  

    beneficio.agregarLote(new LoteHoney("Finca San Luis", 150.0, 1250, 65.0));   
    beneficio.agregarLote(new LoteHoney("Finca Bella Vista", 140.0, 1450, 85.0));
    beneficio.agregarLote(new LoteHoney("Finca El Cedro", 100.0, 900, 20.0));   

    beneficio.agregarLote(new LoteNatural("Finca Monte Azul", 110.0, 1500, 22, 11.0));
    beneficio.agregarLote(new LoteNatural("Finca La Esperanza", 130.0, 1000, 15, 13.5)); 
    beneficio.agregarLote(new LoteNatural("Finca El Alto", 90.0, 1350, 30, 9.0)); 

    beneficio.mostrarInventario();

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n===== RESUMEN =====\n";
    std::cout << "Valor total del inventario: "
        << beneficio.valorTotalInventario() << " colones\n";

    LoteCafe* mejor = beneficio.loteMayorCalidad();
    if (mejor != nullptr) {
        std::cout << "\nLote de mayor calidad:\n";
        std::cout << mejor->toString() << std::endl;
    }

    std::cout << "\nCantidad Lavado: "
        << beneficio.contarPorProceso("Lavado") << std::endl;

    std::cout << "Cantidad Honey: "
        << beneficio.contarPorProceso("Honey") << std::endl;

    std::cout << "Cantidad Natural: "
        << beneficio.contarPorProceso("Natural") << std::endl;

    std::cout << "\nPromedio calidad Lavado: "
        << beneficio.promedioCalidadPorProceso("Lavado") << std::endl;

    std::cout << "Promedio calidad Honey: "
        << beneficio.promedioCalidadPorProceso("Honey") << std::endl;

    std::cout << "Promedio calidad Natural: "
        << beneficio.promedioCalidadPorProceso("Natural") << std::endl;

    return 0;
}