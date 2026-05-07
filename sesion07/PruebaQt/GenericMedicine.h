#ifndef GENERICMEDICINE_H
#define GENERICMEDICINE_H
#include "Medicine.h"
#include <string>

namespace PharmacySystem {

    class GenericMedicine : public Medicine {
    private:

        std::string activeIngredient;

    public:
        GenericMedicine(int id, std::string name, double price,
            int stock, bool needsaPrescription, std::string activeIngredient);

        ~GenericMedicine();

        std::string getActiveIngredient() const;



        virtual std::string getCategory() const override;
        virtual double calculateFinalPrice(int amount) const override;
        virtual std::string getWarning() const override;

    };
}

#endif