#include "Client.h"
#include <iostream>
#include <iomanip>

namespace PharmacySystem {

    Client::Client(int id, const std::string& name, const std::string& identityCard, bool hasActiveCardStatus)
        : id(id), identityCard(identityCard), name(name), hasActiveCardStatus(hasActiveCardStatus) {

    }

    Client::~Client() {

    }

    int Client::getId() const {
        return id;
    }

    std::string Client::getName() const {
        return name;
    }

    std::string Client::getIdentityCard() const {
        return identityCard;
    }

    bool Client::getHasActiveCardStatus() const {
        return hasActiveCardStatus;
    }

    void Client::setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    void Client::setIdentityCard(const std::string& newidentityCard) {
        if (!newidentityCard.empty()) {
            identityCard = newidentityCard;
        }
    }

    bool Client::toggleCardStatus() {
        hasActiveCardStatus = !hasActiveCardStatus;
        return hasActiveCardStatus;

        return true;
    }

    void Client::show() const {
        std::cout << std::left
            << std::setw(8) << id
            << std::setw(15) << name
            << std::setw(12) << identityCard
            << std::setw(10) << (hasActiveCardStatus ? "Activa" : "Inactiva")
            << "\n";
    }

}