#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <cstring>
using namespace std;


class Account{
    protected:
    // common account details
        int accountNumber;
        double interestRate;
        double balance;
        double minBalance;

        // account holder info
        char* fname;
        char* lname;
        char* mobile;
        char* email;
        int pin;

    public:
    // constructors
        Account(int accountNumber, double balance, const char* fname, const char* lname, const char* mobile, const char* email, int pin):
            accountNumber(accountNumber), balance(balance), pin(pin) {
                this->fname = new char[strlen(fname) + 1];
                strcpy(this->fname, fname);

                this->lname = new char[strlen(lname) + 1];
                strcpy(this->lname, lname);

                this->mobile = new char[strlen(mobile) + 1];
                strcpy(this->mobile, mobile);

                this->email = new char[strlen(email) + 1];
                strcpy(this->email, email);
        }
    //destructors
        virtual ~Account(){
            if (fname != nullptr) {
                delete[] fname;
            }
            if (lname != nullptr) {
                delete[] lname;
            }
            if (mobile != nullptr) {
                delete[] mobile;
            }
            if (email != nullptr) {
                delete[] email;
            }
        }
    // SETTER FUNCTIONS
        // void setInterestRate(double interestRate){
        //     this->interestRate = interestRate;
        // }
    
        void setBalance(double balance){
            this->balance = balance;
        }
        // void setMinBalance(double minBalance){
        //     this->minBalance = minBalance;
        // }
        void setFname(const char* fname){
            if (this->fname != nullptr) {
                delete[] this->fname;
            }
            this->fname = new char[strlen(fname) + 1];
            strcpy(this->fname, fname);
        }
        void setLname(const char* lname){
            if (this->lname != nullptr) {
                delete[] this->lname;
            }
            this->lname = new char[strlen(lname) + 1];
            strcpy(this->lname, lname);
        }
        void setMobile(const char* mobile){
            if (this->mobile != nullptr) {
                delete[] this->mobile;
            }
            this->mobile = new char[strlen(mobile) + 1];
            strcpy(this->mobile, mobile);
        }
        void setEmail(const char* email){
            if (this->email != nullptr) {
                delete[] this->email;
            }
            this->email = new char[strlen(email) + 1];
            strcpy(this->email, email);
        }
        void setPin(int pin){
            this->pin = pin;
        }
        // GETTER FUNCTIONS
        const int getAccountNumber() const{
            return accountNumber;
        }
        const double getInterestRate() const{
            return interestRate;
        }
        double getBalance() const{
            return balance;
        }
        const double getMinBalance() const{
            return minBalance;
        }
        const char* getFname() const{
            return fname;
        }
        const char* getLname() const{
            return lname;
        }
        const char* getMobile() const{
            return mobile;
        }
        const char* getEmail() const{
            return email;
        }
        const int getPin() const{
            return pin;
        }
        // This makes account Abstract class
        virtual void display() const=0; // pure virtual function
        void deposit(double amount){
            if(amount > 0){
                cout << "Deposit amount must be greater than 0" << endl;
                return;
            }
            balance += amount;
        }
        // withdraw money function
        void withdraw(double amount){
            // checking balance available
            if(amount > balance){
                cout << "Insufficient balance" << endl;
                return;
            }
            // cannot make balance less than minimum balance
            if(balance - amount < minBalance){
                cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
                return;
            }
            
            balance -= amount;
        }
        void changePin(int newPin){
            pin = newPin;
        }
};
#endif

