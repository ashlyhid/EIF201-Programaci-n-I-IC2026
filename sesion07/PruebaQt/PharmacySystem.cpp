#include "PharmacySystem.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "GenericMedicine.h"
#include "BrandMedication.h"
#include "ControlledMedication.h"
#include "Sale.h"

namespace PharmacySystem {

    void PharmacySystem::resizeMedicines() {

        medicineCapacity *= 2;
        Medicine** newArray = new Medicine * [medicineCapacity];
        Medicine** source = medicines;
        Medicine** destination = newArray;
        for (int i = 0; i < medicineCount; i++, source++, destination++) {
            *destination = *source;
        }
        delete[] medicines;
        medicines = newArray;
    }


    void PharmacySystem::resizeClients() {

        clientCapacity *= 2;
        Client** newArray = new Client * [clientCapacity];
        Client** source = clients;
        Client** destination = newArray;
        for (int i = 0; i < clientCount; i++, source++, destination++) {
            *destination = *source;
        }
        delete[] clients;
        clients = newArray;
    }

    void PharmacySystem::resizeSales() {

        salesCapacity *= 2;

        Sale** newArray = new Sale * [salesCapacity];

        for (int i = 0; i < salesCount; i++) {
            newArray[i] = salesHistory[i];
        }
        delete[] salesHistory;
        salesHistory = newArray;
    }


    PharmacySystem::PharmacySystem() : medicineCount(0), clientCount(0), salesCount(0),
        medicineCapacity(5), clientCapacity(5), salesCapacity(5),
        nextMedicineID(1), nextClientID(1), nextSaleID(1) {

        medicines = new Medicine * [medicineCapacity];
        clients = new Client * [clientCapacity];
        salesHistory = new Sale * [salesCapacity];
    }


    PharmacySystem::~PharmacySystem() {

        for (int i = 0; i < medicineCount; i++) {
            delete medicines[i];
        }
        for (int i = 0; i < clientCount; i++) {
            delete clients[i];
        }
        for (int i = 0; i < salesCount; i++) {
            delete salesHistory[i];
        }
        delete[] medicines;
        delete[] clients;
        delete[] salesHistory;
    }

    bool PharmacySystem::sellMedicine(int clientID, int medicineID, int quantity, std::string date)
    {

        Client* client = findClientByID(clientID);
        Medicine* medicine = findMedicineByID(medicineID);


        if (client == nullptr || medicine == nullptr || medicine->getStock() < quantity) {
            return false;
        }


        double uPrice = medicine->getPrice();
        double subtotal = uPrice * quantity;
        double finalPrice = subtotal;


        if (client->getHasActiveCardStatus()) {
            finalPrice = subtotal * 0.95;
        }

        if (salesCount == salesCapacity) {
            resizeSales();
        }

        salesHistory[salesCount] = new Sale(nextSaleID++, client->getIdentityCard(),
            medicine, quantity, uPrice, finalPrice, date);
        salesCount++;

        medicine->removeStock(quantity);

        return true;
    }

    bool PharmacySystem::registerMedicine(int type, const std::string& name, double price, int stock, bool needsPrescription, std::string extraString, int extraInt) {

        if (medicineCount == medicineCapacity) {
            resizeMedicines();
        }
        Medicine* newMedicine = nullptr;

        if (type == 1) {
            newMedicine = new GenericMedicine(nextMedicineID++, name, price, stock, needsPrescription, extraString);

        }
        else if (type == 2) {
            bool hasPromotion = (extraInt == 1);
            newMedicine = new BrandMedication(nextMedicineID++, name, price, stock, needsPrescription, extraString, hasPromotion);
        }
        else if (type == 3) {
            newMedicine = new ControlledMedication(nextMedicineID++, name, price, stock, extraInt, 1.0);
        }

        if (newMedicine != nullptr) {
            medicines[medicineCount] = newMedicine;
            medicineCount++;
            return true;
        }
        return false;

    }


    Medicine* PharmacySystem::findMedicineByName(const std::string& name)
    {
        Medicine** ptr = medicines;
        for (int i = 0; i < medicineCount; i++, ptr++) {
            if ((*ptr)->getName().find(name) != std::string::npos) {
                std::cout << "\n" << std::left << std::setw(8) << "ID" << std::setw(30)
                    << "Nombre" << std::setw(12) << "Precio" << std::setw(10) << "Stock"
                    << std::setw(10) << "Receta" << "\n" << std::endl;
                std::cout << std::string(70, '-') << "\n" << std::endl;
                return *ptr;
            }
        }
        return nullptr;
    }


    Medicine* PharmacySystem::findMedicineByID(int id)
    {
        for (int i = 0; i < medicineCount; i++) {
            if (medicines[i]->getId() == id) {
                return medicines[i];
            }
        }
        return nullptr;
    }


    void PharmacySystem::listMedicines() const
    {
        if (medicineCount == 0) {
            std::cout << "No hay medicamentos registrados \n";
            return;
        }
        std::cout << "\n" << std::left << std::setw(8) << "ID" << std::setw(30)
            << "Nombre" << std::setw(12) << "Precio" << std::setw(10) << "Stock"
            << std::setw(10) << "Receta" << "\n" << std::endl;
        std::cout << std::string(70, '-') << "\n" << std::endl;

        for (int i = 0; i < medicineCount; i++) {
            medicines[i]->show();
        }
    }

    void PharmacySystem::listSales() const
    {

        if (salesCount == 0) {
            std::cout << "No hay ventas para mostrar en el historial" << std::endl;
            return;
        }
        std::cout << std::endl << std::left << std::setw(8) << "ID" << std::setw(15)
            << "Cédula" << std::setw(20) << "Medicina" << std::setw(10)
            << "Cant." << std::setw(12) << "Total" << std::setw(12) << "Fecha" << "\n";
        std::cout << std::string(80, '-') << "\n";
        for (int i = 0; i < salesCount; i++) {
            std::cout << std::left << std::setw(8) << salesHistory[i]->getId()
                << std::setw(15) << salesHistory[i]->getClientId()
                << std::setw(20) << salesHistory[i]->getSoldMedicine()->getName()
                << std::setw(10) << salesHistory[i]->getQuantity()
                << std::setw(12) << std::fixed << std::setprecision(2) << salesHistory[i]->getFinalPrice()
                << std::setw(12) << salesHistory[i]->getDate() << "\n";
        }
    }




    void PharmacySystem::updateStock(int id, int quantity)
    {
        Medicine* m = findMedicineByID(id);
        if (m == nullptr) {
            std::cout << "No se ha encontrado un medicamento con ese ID " << id << "\n";
            return;
        }
        if (quantity > 0) {
            m->addStock(quantity);
            std::cout << "El stock se ha actualizado. Nuevo stock: " << m->getStock() << " unidades\n";
        }
        else if (quantity < 0) {
            int units = -quantity;
            if (!m->removeStock(units)) {
                std::cout << "Stock insuficiente. Stock actual: " << m->getStock() << "unidades\n";
            }
            else {
                std::cout << "El stock se ha actualizado. Nuevo stock: " << m->getStock() << " unidades\n";
            }
        }
        else {
            std::cout << "La cantidad no puede ser cero \n";
        }
    }


    void PharmacySystem::deleteMedicine(int id)
    {
        for (int i = 0; i < medicineCount; i++) {
            if (medicines[i]->getId() == id) {
                char confirmation;
                std::cout << "¿Desea eliminar \"" << medicines[i]->getName() << "\"? (s/n): ";
                std::cin >> confirmation;
                std::cin.ignore();

                if (confirmation != 's' && confirmation != 'S') {
                    std::cout << "Se cancelo la operacion \n";
                    return;
                }
                delete medicines[i];
                for (int j = i; j < medicineCount - 1; j++) {
                    medicines[j] = medicines[j + 1];
                }
                medicineCount--;
                std::cout << "El medicamento se elimino exitosamente\n";
                return;
            }
        }
        std::cout << "No se ha encontrado un medicamento con ese ID " << id << "\n";
    }


    void PharmacySystem::registerClient(const std::string& name, const std::string& identityCard)
    {

        if (findClient(identityCard) != nullptr) {

            std::cout << "Error, cliente ya registrado." << std::endl;
            return;
        }
        if (clientCount == clientCapacity) {
            resizeClients();
        }
        clients[clientCount] = new Client(nextClientID++, name, identityCard, false);
        clientCount++;

        std::cout << "El cliente se ha registrado correctamente  " << std::endl;

    }


    Client* PharmacySystem::findClient(const std::string& identityCard)
    {
        for (int i = 0; i < clientCount; i++) {
            if (clients[i]->getIdentityCard() == identityCard) {
                std::cout << std::endl << std::left << std::setw(8)
                    << "ID" << std::setw(8)
                    << "Nombre" << std::setw(15)
                    << "Cedula" << std::setw(12)
                    << "Tarjeta de fidelidad" << std::setw(10) << std::endl;
                std::cout << std::string(70, '-') << std::endl;
                return clients[i];
            }
        }
        return nullptr;
    }


    void PharmacySystem::listClients() const
    {
        if (clientCount == 0) {
            std::cout << "No hay clientes registrados" << std::endl;
            return;
        }

        std::cout << std::endl << std::left << std::setw(8)
            << "ID" << std::setw(8)
            << "Nombre" << std::setw(15)
            << "Cedula" << std::setw(12)
            << "Tarjeta de fidelidad" << std::setw(10) << std::endl;
        std::cout << std::string(70, '-') << std::endl;

        for (int i = 0; i < clientCount; i++) {
            clients[i]->show();

        }
    }


    void PharmacySystem::changeCardStatus(const std::string& identityCard)
    {
        Client* c = findClient(identityCard);
        if (c == nullptr) {
            std::cout << "No se encontro un cliente con la cedula: " << identityCard << ".\n";
            return;
        }
        c->toggleCardStatus();
        std::cout << "Tarjeta de fidelidad " << (c->getHasActiveCardStatus() ? "activada" : "desactivada") << " para " << c->getName() << "\n";

    }


    void PharmacySystem::deleteClient(int id)
    {
        for (int i = 0; i < clientCount; i++) {
            if (clients[i]->getId() == id) {
                char confirmation;
                std::cout << "Desea eliminar al cliente \"" << clients[i]->getName() << "\"? (s/n)";
                std::cin >> confirmation;
                std::cin.ignore();

                if (confirmation != 's' && confirmation != 'S') {
                    std::cout << "Se cancelo la operacion \n";
                    return;
                }
                delete clients[i];
                for (int j = i; j < clientCount - 1; j++) {
                    clients[j] = clients[j + 1];
                }
                clientCount--;
                std::cout << "El cliente se elimino exitosamente\n";
                return;
            }
        }
        std::cout << "No se ha encontrado un cliente con ese ID " << id << "\n";
    }


    Client* PharmacySystem::findClientByID(int id) {
        for (int i = 0; i < clientCount; i++) {
            if (clients[i]->getId() == id) {
                return clients[i];
            }
        }
        return nullptr;
    }


}