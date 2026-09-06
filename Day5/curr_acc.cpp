#include "account.h"
#include "curr_acc.h"

#include <iostream>
#include <cstring>
using namespace std;

// parameterised constructor for current account
CurrentAccount::CurrentAccount(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin)
    : Account(accountNumber, balance, fname, lname, mobile, email, pin), transactionCount(0) {
        this->minBalance = 1000.0; // Set the minimum balance for CurrentAccount
        this->interestRate = 0.01; // Set the interest rate for CurrentAccount
        currentAccountCount++;
}

// destructor
CurrentAccount::~CurrentAccount()=default;

// get no. of transctions made
const int CurrentAccount::getTransactionCount() const{
            return transactionCount;
        }

// setter for transactions/day
void CurrentAccount::setTransactionCount(int transactionCount){
            this->transactionCount = transactionCount;
        }
// display current account details
void CurrentAccount::display() const {
            cout << "Current Account Details:" << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << "First Name: " << fname << endl;
            cout << "Last Name: " << lname << endl;
            cout << "Mobile: " << mobile << endl;
            cout << "Email: " << email << endl;
            cout << "Pin: " << pin << endl;
            cout << "Transaction Count: " << transactionCount << endl;
        }