#ifndef BRANDMEDICATION_H
#define BRANDMEDICATION_H
#include "Medicine.h"
#include <string>

namespace PharmacySystem {

    class BrandMedication : public Medicine
    {
    private:
        std::string countryOrigin;
        bool promotionStatus;

    public:
        BrandMedication(int id, std::string name, double price, int stock, bool needsaPrescription, std::string countryOrigin,
            bool promotionStatus);

        ~BrandMedication();

        std::string getCountryOriginn() const;
        bool getPromotionStatus() const;
        void setPromotionStatus(bool status);


        virtual std::string getCategory() const override;
        virtual double calculateFinalPrice(int amount) const override;
        virtual std::string getWarning() const override;

    };
}

#endif