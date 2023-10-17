//
// Created by Aleksander Olsvik on 19.09.2023.
//

#ifndef TASK3_COMMODITY_HPP
#define TASK3_COMMODITY_HPP
#include "string"
using namespace std;

const double tax = 1.25;

class Commodity {
public:
    Commodity(string name_, int id_, double price_);
    string get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double amount) const;
    void set_price(double price);
    double get_price_with_sales_tax() const;
    double get_price_with_sales_tax(double amount) const;
private:
    string name;
    int id;
    double price;
};

Commodity::Commodity(string name_, int id_, double price_): name(name_), id(id_), price(price_) {}

string Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double amount_) const {
    return price*amount_;
}

void Commodity::set_price(double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax() const {
    return price*tax;
}

double Commodity::get_price_with_sales_tax(double amount_) const {
    return price*tax*amount_;
}

#endif //TASK3_COMMODITY_HPP
