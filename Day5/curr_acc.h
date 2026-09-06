#ifndef CURR_ACC_H
#define CURR_ACC_H
#include "account.h"
// child class of Account
class CurrentAccount : public Account{
    private:
    // transcations per day
        int transactionCount;
        static int currentAccountCount;
    public:
        CurrentAccount(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin);
        ~CurrentAccount();
        static int getCurrentAccountCount() {
            return currentAccountCount;
        }
        const int getTransactionCount() const;
        void setTransactionCount(int transactionCount);

        void display() const override;
};

#endif