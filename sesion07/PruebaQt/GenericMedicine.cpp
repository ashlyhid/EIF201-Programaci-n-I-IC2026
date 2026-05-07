#include "GenericMedicine.h"
#include <sstream>

namespace PharmacySystem {




    GenericMedicine::GenericMedicine(int id, std::string name, double price, int stock,
        bool needsaPrescription, std::string activeIngredient) : Medicine(id, name, price, stock, needsaPrescription),
        activeIngredient(activeIngredient.empty() ? "No especificado" : activeIngredient) {
    }

    GenericMedicine::~GenericMedicine() {
    }

    std::string GenericMedicine::getActiveIngredient() const {
        return activeIngredient;
    }

    std::string GenericMedicine::getCategory() const {
        return "Generico";
    }

    double GenericMedicine::calculateFinalPrice(int amount) const {
        double subtotal = getPrice() * amount;
        double discount = subtotal * 0.10;
        return subtotal - discount;
    }

    std::string GenericMedicine::getWarning() const {
        std::ostringstream oss;
        oss << "Medicamento generico: contiene el mismo principio activo que su "
            << "equivalente de marca pero a menor costo. Aplica un descuento "
            << "del 10% sobre el precio de lista. Principio activo: "
            << activeIngredient;
        return oss.str();

    }

}   