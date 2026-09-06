// #include "account.h"
#include <iostream>
#ifndef SAV_ACC_H
#define SAV_ACC_H
class SavingAccount : public Account {
    private:
        static int SavingsAccountCount;
        int checkBookNumber;
        static inline int nextCheckBookNumber = 1000; // Static member to keep track of the next checkbook number

    public:
        SavingAccount(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin);
        ~SavingAccount();
        static int getSavingsAccountCount() {
            return SavingsAccountCount;
        }
        void display() const override;

};
#endif