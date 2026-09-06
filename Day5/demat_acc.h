#ifndef DEMAT_ACC_H
#define DEMAT_ACC_H
#include "share.h"
#include "account.h"
// child class of Account

class DematAccount : public Account {
    
    private:
        // maximum number shares u can add
        static const int max_shares=100;
        // counting Demat Accounts present
        static int DematAccountCount;
        Shares *share[max_shares]; //SHARE OBJECT
        int shareCount; //NUMBER OF SHARES IN DEMAT ACCOUNT
    public:
        DematAccount(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin);
        ~DematAccount();
        void display() const override;
        void buyShares();
        void sellShares(char* shareName, int quantity, double sellingPrice, const char* dateOfSelling);
        void displayShareDetails() const;
        static int getDematAccountCount();
    };

#endif