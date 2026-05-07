#ifndef PharmacySystem_H
#define PharmacySystem_H
#include <vector>
#include "Medicine.h"
#include "Client.h"
#include "Sale.h"

#include <string>

namespace PharmacySystem {

    class PharmacySystem {

    private:
        Medicine** medicines;
        Client** clients;
        Sale** salesHistory;


        int medicineCount;
        int clientCount;
        int salesCount;

        int medicineCapacity;
        int clientCapacity;
        int salesCapacity;

        int nextMedicineID;
        int nextClientID;
        int nextSaleID;

        void resizeSales();
        void resizeMedicines();
        void resizeClients();

    public:

        PharmacySystem();
        ~PharmacySystem();

        Client** getClientsArray() const {
            return clients;
        }

        int getClientCount() const {
            return clientCount;
        }

        bool sellMedicine(int clientID, int medicineID, int quantity, std::string date);

        bool registerMedicine(int type, const std::string& name, double price,
            int stock, bool needsPrescription, std::string extraString, int extraInt);
        Medicine* findMedicineByName(const std::string& name);
        Medicine* findMedicineByID(int id);
        void listMedicines() const;
        void listSales()const;
        void updateStock(int id, int quantity);
        void deleteMedicine(int id);

        void registerClient(const std::string& name, const std::string& identityCard);
        Client* findClient(const std::string& identityCard);
        void listClients() const;
        void changeCardStatus(const std::string& identityCard);
        void deleteClient(int id);

        Client* findClientByID(int id);



    };
}
#endif