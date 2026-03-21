#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

namespace UNA {

    class Vehicle {
    private:
        std::string placa;
        std::string marca;
        int anio;
        double kilometros;
        bool activo;

    public:
        Vehicle(const std::string& placa, const std::string& marca, int anio, double kilometros);

        std::string getPlaca() const;
        std::string getMarca() const;
        int getAnio() const;
        double getKilometros() const;
        bool getActivo() const;

        void registrarKm(double km);
        void desactivar();
        void reactivar();
        void mostrar() const;
    };

}

#endif