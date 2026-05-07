#ifndef Client_H
#define Client_H
#include <string>

namespace PharmacySystem {

    class Client {
    public:
        Client(int id = 0, const std::string& name = "", const std::string& identityCard = "", bool hasActiveCardStatus = false);
        ~Client();

        int getId() const;
        std::string getName() const;
        std::string getIdentityCard() const;
        bool getHasActiveCardStatus() const;

        void setName(const std::string& name);
        void setIdentityCard(const std::string& identityCard);
        bool toggleCardStatus();
        void show() const;

    private:
        int id;
        std::string identityCard;
        std::string name;
        bool hasActiveCardStatus;
    };

}
#endif