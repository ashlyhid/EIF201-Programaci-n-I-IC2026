#include "ControlledMedication.h"
#include <sstream>

PharmacySystem::ControlledMedication::ControlledMedication(int id, std::string name, double price, int stock,
    int controLevel, double dailyMaxDose) : Medicine(id, name, price, stock, true), dailyMaxDose(dailyMaxDose > 0 ? dailyMaxDose : 1.0) {
    if (controLevel < 1) {
        this->controLevel = 1;
    }
    else if (controLevel > 4) {
        this->controLevel = 4;
    }
    else {
        this->controLevel = controLevel;
    }
}

PharmacySystem::ControlledMedication::~ControlledMedication() {
}

int PharmacySystem::ControlledMedication::getControLevel() const {
    return controLevel;
}

double PharmacySystem::ControlledMedication::getDailyMaxDose() const {
    return dailyMaxDose;
}

std::string PharmacySystem::ControlledMedication::getCategory() const {
    return "Controlado";
}

double PharmacySystem::ControlledMedication::calculateFinalPrice(int amount) const {
    double subtotal = getPrice() * amount;
    double surcharge = subtotal * 0.05;

    return subtotal + surcharge;
}

std::string PharmacySystem::ControlledMedication::getWarning() const {
    std::ostringstream oss;
    oss << "MEDICAMENTO CONTROLADO (Nivel " << controLevel << "): "
        << "Requiere receta medica obligatoria. "
        << "Dosis maxima diaria: " << dailyMaxDose << " mg. "
        << "Se aplica un recargo del 5% por manejo especial. "
        << "Dispensacion sujeta a regulacion sanitaria.";
    return oss.str();
}
