#include "account.h"
#include "sav_acc.h"
#include <iostream>
#include <cstring>
using namespace std;

// constructor
SavingAccount::SavingAccount(int accountNumber, double balance, const char *fname, const char *lname, const char *mobile, const char *email, int pin) : Account(accountNumber, balance, fname, lname, mobile, email, pin)
{
    SavingsAccountCount++;
    interestRate = 0.04;  // Set the interest rate for SavingAccount
    minBalance = 20000.0; // Set the minimum balance for SavingAccount
    checkBookNumber = nextCheckBookNumber++;
}

// destructor
SavingAccount::~SavingAccount() = default;
void SavingAccount::display() const
{
    cout << "Saving Account Details:" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Mobile: " << mobile << endl;
    cout << "Email: " << email << endl;
    cout << "Pin: " << pin << endl;
    cout << "Check Book Number: " << checkBookNumber << endl;
}