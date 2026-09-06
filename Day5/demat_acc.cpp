#include <iostream>
#include "account.h"
#include "share.h"
#include "demat_acc.h"

using namespace std;


DematAccount::DematAccount(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin):
    Account(accountNumber, balance, fname, lname, mobile, email, pin) {
        DematAccountCount++;
        interestRate = 0.0; // Set the interest rate for DematAccount
        minBalance = 0.0; // Set the minimum balance for DematAccount
        shareCount = 0; // Initialize share count to 0
    }

void DematAccount::buyShares() {
    // Implementation for buying shares
    cout << "Buying shares..." << endl;
    cout << "Enter share name: ";
    char shareName[50];
    cin >> shareName;
    cout << "Enter quantity: ";
    int quantity;
    cin >> quantity;
    cout << "Enter buying price: ";
    double buyingPrice;
    cin >> buyingPrice;
    cout << "Enter selling price: ";
    double sellingPrice;
    cin >> sellingPrice;
    cout << "Enter date of purchase: ";
    char dateOfPurchase[20];
    cin >> dateOfPurchase;
    cout << "Enter date of selling: ";
    char dateOfSelling[20];
    cin >> dateOfSelling;
    cout << "Shares bought successfully!" << endl;

    if(shareCount < max_shares) {
        share[shareCount] = new Shares(shareName, quantity, buyingPrice, sellingPrice, dateOfPurchase, dateOfSelling);
        shareCount++;
    } else {
        cout << "Maximum number of shares reached." << endl;
    }

}
void DematAccount::sellShares(char* shareName, int quantity, double sellingPrice, const char* dateOfSelling) {
    // Implementation for selling shares
    cout << "Selling shares..." << endl;
    for(int i = 0; i < shareCount; i++) {
        if(strcmp(share[i]->getName(), shareName) == 0) {
            if(share[i]->getQuantity() >= quantity) {
                share[i]->setQuantity(share[i]->getQuantity() - quantity);
                share[i]->setSellingPrice(sellingPrice);
                share[i]->setDateOfSelling(dateOfSelling);
                cout << "Shares sold successfully!" << endl;
                return;
            } else {
                cout << "Not enough shares to sell." << endl;
                return;
            }
        }
    }
    cout << "Share not found." << endl;
}

int DematAccount::getDematAccountCount() {
    return DematAccountCount;
}

void DematAccount::display() const {
    cout << "Demat Account Details:" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Mobile: " << mobile << endl;
    cout << "Email: " << email << endl;
    cout << "Pin: " << pin << endl;
    cout << "Number of Shares: " << shareCount << endl;
}

DematAccount::~DematAccount()=default;
