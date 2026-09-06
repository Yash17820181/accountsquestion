#ifndef SHARES_H
#define SHARES_H
#include <iostream>
using namespace std;

// has-a realaltionship with demat account
class Shares
{
private:
    // share info
    char *name;
    int quantity;
    double buyingPrice;
    double sellingPrice;
    char *dateOfPurchase;
    char *dateOfSelling;

public:
    // constructors
    Shares(const char *name, int quantity, double buyingPrice, const char *dateOfPurchase)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->quantity = quantity;
        this->buyingPrice = buyingPrice;

        this->dateOfPurchase = new char[strlen(dateOfPurchase) + 1];
        strcpy(this->dateOfPurchase, dateOfPurchase);

        this->sellingPrice = 0.0;      // Initialize selling price to 0
        this->dateOfSelling = nullptr; // Initialize date of selling to nullptr
    }
    Shares(const char *name, int quantity, double buyingPrice, double sellingPrice, const char *dateOfPurchase, const char *dateOfSelling)
    {

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->quantity = quantity;
        this->buyingPrice = buyingPrice;
        this->sellingPrice = sellingPrice;

        this->dateOfPurchase = new char[strlen(dateOfPurchase) + 1];
        strcpy(this->dateOfPurchase, dateOfPurchase);

        this->dateOfSelling = new char[strlen(dateOfSelling) + 1];
        strcpy(this->dateOfSelling, dateOfSelling);
    }
    // destructor
    ~Shares()
    {
        delete[] name;
        delete[] dateOfPurchase;
        delete[] dateOfSelling;
    }

    // SETTER FUNCTIONS
    // void setName(const char* name);
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    // void setBuyingPrice(double buyingPrice);
    void setSellingPrice(double sellingPrice)
    {
        this->sellingPrice = sellingPrice;
    }
    // void setDateOfPurchase(const char* dateOfPurchase);
    void setDateOfSelling(const char *dateOfSelling)
    {
        this->dateOfSelling = new char[strlen(dateOfSelling) + 1];
        strcpy(this->dateOfSelling, dateOfSelling);
    }

    // GETTER FUNCTIONS
    const char *getName() const
    {
        return name;
    }
    int getQuantity() const
    {
        return quantity;
    }
    // double getBuyingPrice() const;
    double getSellingPrice() const
    {
        return sellingPrice;
    }
    // const char* getDateOfPurchase() const;
    const char *getDateOfSelling() const
    {
        return dateOfSelling;
    }

    // display share details
    void display() const
    {

        cout << "Share Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Buying Price: " << buyingPrice << endl;
        cout << "Selling Price: " << sellingPrice << endl;
        cout << "Date of Purchase: " << dateOfPurchase << endl;
        cout << "Date of Selling: " << dateOfSelling << endl;
    }
};

#endif