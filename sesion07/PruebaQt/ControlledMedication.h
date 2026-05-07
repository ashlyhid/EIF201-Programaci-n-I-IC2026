#ifndef CONTROLLEDMEDICATION_H
#define CONTROLLEDMEDICATION_H
#include "Medicine.h"
#include <string>

namespace PharmacySystem {


    class ControlledMedication : public Medicine
    {
    private:
        int controLevel;
        double dailyMaxDose;

    public:
        ControlledMedication(int id, std::string name,
            double price, int stock, int controLevel,
            double dailyMaxDose);

        ~ControlledMedication();

        int getControLevel() const;
        double getDailyMaxDose() const;



        virtual std::string getCategory() const override;
        virtual double calculateFinalPrice(int amount) const override;
        virtual std::string getWarning() const override;
    };

}

#endif
