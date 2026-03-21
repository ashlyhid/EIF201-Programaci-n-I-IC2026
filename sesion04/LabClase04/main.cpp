#include <iostream>
#include <string>
#include "vehicle.h"
#include "Flota.h"

using namespace UNA;

int main() {
    Flota flota;
    int opcion;

    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Registrar vehiculo\n";
        std::cout << "2. Buscar vehiculo por placa\n";
        std::cout << "3. Mostrar vehiculos por marca\n";
        std::cout << "4. Registrar kilometros a un vehiculo\n";
        std::cout << "5. Desactivar vehiculo (fuera de servicio)\n";
        std::cout << "6. Reactivar vehiculo\n";
        std::cout << "7. Eliminar vehiculo (dar de baja definitiva)\n";
        std::cout << "8. Mostrar flota completa\n";
        std::cout << "9. Mostrar vehiculos activos actualmente\n";
        std::cout << "10. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        std::cin.ignore();

        switch (opcion) {
        case 1: {
            std::string placa, marca;
            int anio;
            double kilometros;

            std::cout << "Ingrese la placa: ";
            std::getline(std::cin, placa);

            std::cout << "Ingrese la marca: ";
            std::getline(std::cin, marca);

            std::cout << "Ingrese el anio: ";
            std::cin >> anio;

            std::cout << "Ingrese los kilometros: ";
            std::cin >> kilometros;

            std::cin.ignore();

            Vehicle* nuevo = new Vehicle(placa, marca, anio, kilometros);
            flota.agregar(nuevo);
            break;
        }

        case 2: {
            std::string placa;
            Vehicle* encontrado = nullptr;

            do {
                std::cout << "Ingrese la placa a buscar: ";
                std::getline(std::cin, placa);

                encontrado = flota.buscarPorPlaca(placa);

                if (encontrado == nullptr) {
                    std::cout << "Vehiculo no encontrado. Intente nuevamente.\n";
                }

            } while (encontrado == nullptr);

            encontrado->mostrar();
            break;
        }
        case 3: {
            std::string marca;
            std::cout << "Ingrese la marca a buscar: ";
            std::getline(std::cin, marca);

            flota.mostrarPorMarca(marca);
            break;
        }

        case 4: {
            std::string placa;
            double km;

            std::cout << "Ingrese la placa del vehiculo: ";
            std::getline(std::cin, placa);

            Vehicle* encontrado = flota.buscarPorPlaca(placa);

            if (encontrado != nullptr) {
                std::cout << "Ingrese la cantidad de kilometros a registrar: ";
                std::cin >> km;
                std::cin.ignore();

                encontrado->registrarKm(km);
            }
            else {
                std::cout << "Vehiculo no encontrado.\n";
            }
            break;
        }

        case 5: {
            std::string placa;
            std::cout << "Ingrese la placa del vehiculo a desactivar: ";
            std::getline(std::cin, placa);

            Vehicle* encontrado = flota.buscarPorPlaca(placa);

            if (encontrado != nullptr) {
                encontrado->desactivar();
            }
            else {
                std::cout << "Vehiculo no encontrado.\n";
            }
            break;
        }

        case 6: {
            std::string placa;
            std::cout << "Ingrese la placa del vehiculo a reactivar: ";
            std::getline(std::cin, placa);

            Vehicle* encontrado = flota.buscarPorPlaca(placa);

            if (encontrado != nullptr) {
                encontrado->reactivar();
            }
            else {
                std::cout << "Vehiculo no encontrado.\n";
            }
            break;
        }

        case 7: {
            std::string placa;
            std::cout << "Ingrese la placa del vehiculo a eliminar: ";
            std::getline(std::cin, placa);

            flota.eliminar(placa);
            break;
        }

        case 8: {
            flota.mostrarTodos();
            break;
        }

        case 9: {
            std::cout << "Cantidad de vehiculos activos: " << flota.contarActivos() << "\n";
            break;
        }

        case 10: {
            std::cout << "Saliendo del programa...\n";
            break;
        }

        default:
            std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 10);

    return 0;
}