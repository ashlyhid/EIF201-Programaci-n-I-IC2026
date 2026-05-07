#ifndef Medicine_H
#define Medicine_H
#include<string>

namespace PharmacySystem {


    class Medicine
    {
    private:

        int id;
        std::string name;
        double price;
        int stock;
        bool needsaPrescription;


    public:


        Medicine(int id, std::string name, double price, int stock, bool needsaPrescription);
        virtual ~Medicine();

        int getId() const;
        std::string getName() const;
        double getPrice() const;
        int getStock()const;
        bool getNeedsaPrescription() const;

        void setName(std::string name);
        void setPrice(double price);

        bool addStock(int stock);
        bool removeStock(int stock);
        void show() const;

        virtual std::string getCategory() const = 0;
        virtual double calculateFinalPrice(int amount) const = 0;
        virtual std::string getWarning() const = 0;
    };


}
#endif