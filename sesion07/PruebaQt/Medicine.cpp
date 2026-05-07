#include "Medicine.h"
#include <iostream>
#include <iomanip>


namespace PharmacySystem {


    Medicine::Medicine(int id, std::string name, double price, int stock, bool needsaPrescription)
    {
        this->id = id;


        if (name.empty()) {
            this->name = "Sin nombre";
        }
        else {
            this->name = name;
        }


        if (price > 0) {
            this->price = price;
        }
        else {
            this->price = 0.0;
        }


        if (stock >= 0) {
            this->stock = stock;
        }
        else {
            this->stock = 0;
        }

        this->needsaPrescription = needsaPrescription;


    }

    Medicine::~Medicine()
    {
    }

    int Medicine::getId() const
    {
        return this->id;
    }

    std::string Medicine::getName() const
    {
        return this->name;
    }

    double Medicine::getPrice() const
    {
        return this->price;
    }

    int Medicine::getStock() const
    {
        return this->stock;
    }

    bool Medicine::getNeedsaPrescription() const
    {


        return this->needsaPrescription;
    }

    void Medicine::setName(std::string name)
    {

        if (!name.empty()) {

            this->name = name;

        }

    }

    void Medicine::setPrice(double price)
    {

        if (price > 0) {
            this->price = price;
        }

    }

    bool Medicine::addStock(int stock)
    {

        if (stock > 0) {
            this->stock = this->stock + stock;
            return true;
        }
        else {
            return false;
        }

    }

    bool Medicine::removeStock(int stock)
    {

        if (stock <= this->stock) {
            this->stock = this->stock - stock;
            return true;
        }
        else {
            return false;
        }

    }

    void Medicine::show() const {
        std::cout << std::left
            << std::setw(8) << id
            << std::setw(30) << name
            << std::setw(12) << std::fixed << std::setprecision(2) << price
            << std::setw(10) << stock
            << std::setw(10) << (needsaPrescription ? "Si" : "No")
            << "\n";
    }
}