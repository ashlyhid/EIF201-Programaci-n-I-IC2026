#ifndef SALE_H
#define SALE_H
#include <string>
#include "Medicine.h"
#include "Client.h"
namespace  PharmacySystem {

    class Sale
    {

    private:

        int id;
        std::string clientId;
        Medicine* soldMedicine;
        int quantity;
        double unitPrice;
        double finalPrice;
        std::string date;




    public:

        Sale(int id, std::string clientId, Medicine* medicine, int quantity,
            double unitPrice, double finalPrice, std::string date);



        int getId()const;
        std::string getClientId()const;
        Medicine* getSoldMedicine()const;
        int getQuantity()const;
        double getUnitPrice()const;
        double getFinalPrice()const;
        std::string getDate()const;

        ~Sale();


    };



}


#endif