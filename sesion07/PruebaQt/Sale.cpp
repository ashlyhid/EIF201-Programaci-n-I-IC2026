#include "Sale.h"
#include "Medicine.h"

namespace PharmacySystem {
    Sale::Sale(int id, std::string clientId, Medicine* medicine, int quantity, double unitPrice, double finalPrice, std::string date)
    {

        this->id = id;
        this->clientId = clientId;
        this->soldMedicine = medicine;
        this->quantity = quantity;
        this->unitPrice = unitPrice;
        this->finalPrice = finalPrice;
        this->date = date;



    }

    int Sale::getId() const {
        return id;
    }

    std::string Sale::getClientId() const
    {
        return clientId;
    }

    Medicine* Sale::getSoldMedicine() const
    {
        return soldMedicine;
    }

    int Sale::getQuantity() const
    {
        return quantity;
    }

    double Sale::getUnitPrice() const
    {
        return unitPrice;
    }

    double Sale::getFinalPrice() const
    {
        return finalPrice;
    }

    std::string Sale::getDate() const
    {
        return date;
    }

    Sale::~Sale() {

    }



}
