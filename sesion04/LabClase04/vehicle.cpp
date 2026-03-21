#include "vehicle.h"
#include <iostream>

namespace UNA {

    Vehicle::Vehicle(const std::string& placa, const std::string& marca, int anio, double kilometros)
        : placa(placa), marca(marca), anio(anio), kilometros(kilometros), activo(true) {
    }

    std::string Vehicle::getPlaca() const {
        return placa;
    }

    std::string Vehicle::getMarca() const {
        return marca;
    }

    int Vehicle::getAnio() const {
        return anio;
    }

    double Vehicle::getKilometros() const {
        return kilometros;
    }

    bool Vehicle::getActivo() const {
        return activo;
    }

    void Vehicle::registrarKm(double km) {
        if (!activo) {
            std::cout << "ERROR: El vehiculo se encuentra fuera de servicio.\n";
            return;
        }

        if (km <= 0) {
            std::cout << "ERROR: Los kilometros deben ser positivos.\n";
            return;
        }

        kilometros += km;
        std::cout << "Kilometros registrados con exito.\n";
    }

    void Vehicle::desactivar() {
        if (!activo) {
            std::cout << "El vehiculo ya estaba fuera de servicio.\n";
            return;
        }

        activo = false;
        std::cout << "Vehiculo desactivado con exito.\n";
    }

    void Vehicle::reactivar() {
        if (activo) {
            std::cout << "El vehiculo ya estaba activo.\n";
            return;
        }

        activo = true;
        std::cout << "Vehiculo reactivado con exito.\n";
    }

    void Vehicle::mostrar() const {
        std::cout << "\n";
        std::cout << "-------------------------\n";
        std::cout << "Placa: " << placa << "\n";
        std::cout << "Marca: " << marca << "\n";
        std::cout << "Anio: " << anio << "\n";
        std::cout << "Kilometros: " << kilometros << "\n";
        std::cout << "Estado: " << (activo ? "ACTIVO" : "FUERA DE SERVICIO") << "\n";
        std::cout << "-------------------------\n";
    }

}