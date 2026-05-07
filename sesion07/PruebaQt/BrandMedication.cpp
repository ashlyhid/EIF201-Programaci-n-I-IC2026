#include "BrandMedication.h"



PharmacySystem::BrandMedication::BrandMedication(int id, std::string name, double price, int stock,
    bool needsaPrescription, std::string countryOrigin, bool promotionStatus) : Medicine(id, name, price, stock, needsaPrescription),
    countryOrigin(countryOrigin.empty() ? "No especificado" : countryOrigin), promotionStatus(promotionStatus) {
}

PharmacySystem::BrandMedication::~BrandMedication() {
}


std::string PharmacySystem::BrandMedication::getCountryOriginn() const {
    return countryOrigin;
}

bool PharmacySystem::BrandMedication::getPromotionStatus() const {
    return promotionStatus;
}

void PharmacySystem::BrandMedication::setPromotionStatus(bool status) {
    promotionStatus = status;
}

std::string PharmacySystem::BrandMedication::getCategory() const {
    return "Marca";
}

double PharmacySystem::BrandMedication::calculateFinalPrice(int amount) const {
    double subtotal = getPrice() * amount;
    if (promotionStatus) {
        double discount = subtotal * 0.15;
        return subtotal - discount;
    }
    return subtotal;
}

std::string PharmacySystem::BrandMedication::getWarning() const {
    std::string msg = "Medicamento de marca: fabricado en " + countryOrigin + ". ";
    if (promotionStatus) {
        msg += "Actualmente EN PROMOCION con un 15% de descuento.";
    }
    else {
        msg += "Sin promocion activa, se aplica precio de lista normal.";
    }
    return msg;

}

