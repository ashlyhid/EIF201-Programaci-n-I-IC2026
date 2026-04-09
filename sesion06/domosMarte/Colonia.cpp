#include "Colonia.h"
#include <iostream>
#include <iomanip>

namespace EIF201 {

    Colonia::Colonia(const std::string& nombre, const std::string& planeta, int cantidadDomos)
        : name(name), planets(planets), cantidadDomos(cantidadDomos) {
        domos = new Domo * [cantidadDomos];
        for (int i = 0; i < cantidadDomos; i++) {
            domos[i] = 0;
        }
    }

    Colonia::~Colonia() {
        for (int i = 0; i < cantidadDomos; i++) {
            delete domos[i];
        }
        delete[] domos;
    }

    void Colonia::configurarDomo(int indice, int codigo, typeDomo tipo, double capacidadOxigeno, int maxOcupantes) {
        if (indice >= 0 && indice < cantidadDomos) {
            delete domos[indice];
            domos[indice] = new Domo(codigo, tipo, capacidadOxigeno, maxOcupantes);
        }
    }

    std::string Colonia::getName() const {
        return name;
    }

    std::string Colonia::getPlanets() const {
        return planets;
    }

    int Colonia::getCantidadDomos() const {
        return cantidadDomos;
    }

    Domo* Colonia::getDomo(int indice) const {
        if (indice >= 0 && indice < cantidadDomos) {
            return domos[indice];
        }
        return 0;
    }

    bool Colonia::asignarInteligente(Colono* colono) {
        int mejorIndice = -1;
        double mejorRatio = -1.0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0 && domos[i]->puedeIngresar(colono)) {
                double ratio = domos[i]->ratioSiIngresa(colono);
                if (ratio > mejorRatio) {
                    mejorRatio = ratio;
                    mejorIndice = i;
                }
            }
        }

        if (mejorIndice == -1) {
            return false;
        }

        return domos[mejorIndice]->addColono(colono);
    }

    bool Colonia::transferirColono(int idColono, int codigoOrigen, int codigoDestino) {
        Domo* origen = 0;
        Domo* destino = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0) {
                if (domos[i]->getCodigo() == codigoOrigen) origen = domos[i];
                if (domos[i]->getCodigo() == codigoDestino) destino = domos[i];
            }
        }

        if (origen == 0 || destino == 0) return false;

        Colono* colono = origen->searchColonoId(idColono);
        if (colono == 0) return false;

        if (!destino->puedeIngresar(colono)) {
            return false;
        }

        Colono* extraido = 0;
        if (!origen->deleteColonoId(idColono, extraido)) {
            return false;
        }

        if (!destino->addColono(extraido)) {
            origen->addColono(extraido);
            return false;
        }

        return true;
    }

    int Colonia::evacuarDomo(int codigoDomo) {
        Domo* origen = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0 && domos[i]->getCodigo() == codigoDomo) {
                origen = domos[i];
                break;
            }
        }

        if (origen == 0) return 0;

        origen->sellar();

        int maxColonos = origen->getCantidadColonos();
        Colono** evacuados = new Colono * [maxColonos];
        int cantidadEvacuados = origen->evacuacionForzosa(evacuados, maxColonos);

        int noReubicados = 0;

        for (int i = 0; i < cantidadEvacuados; i++) {
            if (evacuados[i] == nullptr) continue; 
            if (!asignarInteligente(evacuados[i])) {
                noReubicados++;
                std::cout << "No se pudo reubicar a: " << evacuados[i]->getName() << std::endl;
            }
        }

        delete[] evacuados;
        return noReubicados;
    }

    int Colonia::rebalancear() {
        int exitosos = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] == 0) continue;

            while (domos[i]->ratioOxigeno() < 1.3 && domos[i]->getCantidadColonos() > 0) {
                bool movio = false;

                for (int j = 0; j < domos[i]->getCantidadColonos(); j++) {

                }

                Colono* candidato = 0;
                int idCandidato = -1;

                for (int id = 1; id <= 1000; id++) {
                    candidato = domos[i]->searchColonoId(id);
                    if (candidato != 0) {
                        idCandidato = id;
                        break;
                    }
                }

                if (candidato == 0) break;

                int mejorDestino = -1;
                double mejorRatio = -1.0;

                for (int k = 0; k < cantidadDomos; k++) {
                    if (k == i || domos[k] == 0) continue;

                    if (domos[k]->puedeIngresar(candidato)) {
                        double ratio = domos[k]->ratioSiIngresa(candidato);
                        if (ratio >= 1.3 && ratio > mejorRatio) {
                            mejorRatio = ratio;
                            mejorDestino = k;
                        }
                    }
                }

                if (mejorDestino == -1) {
                    break;
                }

                if (transferirColono(idCandidato, domos[i]->getCodigo(), domos[mejorDestino]->getCodigo())) {
                    exitosos++;
                    movio = true;
                }

                if (!movio) {
                    break;
                }
            }
        }

        return exitosos;
    }

    Colono* Colonia::buscarColono(int idColono, Domo*& domoEncontrado) const {
        domoEncontrado = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0) {
                Colono* c = domos[i]->searchColonoId(idColono);
                if (c != 0) {
                    domoEncontrado = domos[i];
                    return c;
                }
            }
        }

        return 0;
    }

    void Colonia::tableroControl() const {
        std::cout << "\n=== TABLERO DE CONTROL ===\n";
        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0) {
                domos[i]->mostrar();
            }
        }
    }

    void Colonia::alertOxigeno(double umbral) const {
        std::cout << "\n=== ALERTA DE OXIGENO (< " << umbral << ") ===\n";
        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0 && domos[i]->ratioOxigeno() < umbral) {
                domos[i]->mostrar();
            }
        }
    }

    int Colonia::productividadPorEspe(Especiality especiality) const {
        int total = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] == 0) continue;

            for (int id = 1; id <= 1000; id++) {
                Colono* c = domos[i]->searchColonoId(id);
                if (c != 0 && c->getEspeciality() == especiality) {
                    total += c->getProductividad();
                }
            }
        }

        return total;
    }

    void Colonia::globalStats() const {
        int totalColonos = 0;
        double consumoGlobal = 0.0;
        double capacidadGlobal = 0.0;
        int productividadTotal = 0;

        for (int i = 0; i < cantidadDomos; i++) {
            if (domos[i] != 0) {
                totalColonos += domos[i]->getCantidadColonos();
                consumoGlobal += domos[i]->consumoActual();
                capacidadGlobal += domos[i]->getCapacidadOxigeno();

                for (int id = 1; id <= 1000; id++) {
                    Colono* c = domos[i]->searchColonoId(id);
                    if (c != 0) {
                        productividadTotal += c->getProductividad();
                    }
                }
            }
        }

        std::cout << "\n=== ESTADISTICAS GLOBALES ===\n";
        std::cout << "Total colonos: " << totalColonos << std::endl;
        std::cout << "Consumo global O2: " << consumoGlobal << std::endl;
        std::cout << "Capacidad global O2: " << capacidadGlobal << std::endl;
        std::cout << "Productividad total: " << productividadTotal << std::endl;
    }

}