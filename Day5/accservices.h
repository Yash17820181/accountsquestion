#ifndef ACCSERVICES_H
#define ACCSERVICES_H

#include <iostream>
#include "account.h"
#include "curr_acc.h"
#include "sav_acc.h"
#include "demat_acc.h"
#include "share.h"

using namespace std;

class AccountService
{
public:
    // Adding account
    static void addAccount(Account *accounts[], int maxAccounts, int &count)
    {

        if (count >= maxAccounts)
        {
            cout << "Maximum number of accounts reached." << endl;
            return;
        }

        cout << "Adding a new account..." << endl;

        cout << "Select account type (1: Current, 2: Savings, 3: Demat): ";
        int accountType;
        cin >> accountType;

        cout << "Enter account number: ";
        int accountNumber;
        cin >> accountNumber;

        cout << "Enter first name: ";
        char fname[50];
        cin >> fname;

        cout << "Enter last name: ";
        char lname[50];
        cin >> lname;

        cout << "Enter mobile number: ";
        char mobile[15];
        cin >> mobile;

        cout << "Enter email: ";
        char email[50];
        cin >> email;

        cout << "Enter initial balance: ";
        double initialBalance;
        cin >> initialBalance;

        cout << "Enter pin: ";
        int pin;
        cin >> pin;

        // implicit upcasting
        if (accountType == 1)
        {
            accounts[count] = new CurrentAccount(accountNumber, initialBalance, fname, lname, mobile, email, pin);
        }
        else if (accountType == 2)
        {
            accounts[count] = new SavingAccount(accountNumber, initialBalance, fname, lname, mobile, email, pin);
        }
        else if (accountType == 3)
        {
            accounts[count] = new DematAccount(accountNumber, initialBalance, fname, lname, mobile, email, pin);
        }
        else
        {
            cout << "Invalid account type selected." << endl;
            return;
        }
        count++;
        accounts[count - 1]->display();
    }

    static void displayAllAccountDetails(Account *accounts[], int count)
    {
        // displaying all accounts with details
        cout << "Displaying account details..." << endl;
        for (int i = 0; i < count; i++)
        {
            accounts[i]->display();
        }
    }
    static Account *findAccountByNumber(Account *accounts[], int count, int accountNumber)
    {
        // searching account by Account Number/id
        for (int i = 0; i < count; i++)
        {
            if (accounts[i]->getAccountNumber() == accountNumber)
            {
                return accounts[i];
            }
        }
        return nullptr;
    }
    static void closeAccount(Account *accounts[], int &count)
    {
        // deleting account
        cout << "Closing an account..." << endl;
        cout << "Enter account number to close: ";
        int accountNumber;
        cin >> accountNumber;

        Account *account = findAccountByNumber(accounts, count, accountNumber);
        if (account != nullptr)
        {
            delete account;
        }
        else
        {
            cout << "Account not found." << endl;
            return;
        }
    }
    static void withdrawMoney(Account *accounts[], int count)
    {
        cout << "Enter Ammount to withdraw: ";
        double amount;
        cin >> amount;
        cout << "Enter Account Number: ";
        int accountNumber;
        cin >> accountNumber;
        // withdrawing money from account using account Number
        Account *account = findAccountByNumber(accounts, count, accountNumber);
        if (dynamic_cast<CurrentAccount *>(account) != nullptr || dynamic_cast<SavingAccount *>(account) != nullptr || dynamic_cast<DematAccount *>(account) != nullptr)
        {
            account->withdraw(amount);
            cout << "Withdrawal successful. New balance: " << account->getBalance() << endl;
        }
        else
        {
            cout << "Invalid account type for withdrawal." << endl;
        }
    }
    static void depositMoney(Account *accounts[], int count)
    {
        // depositing money in account using account Number
        cout << "Enter Ammount to deposit: ";
        double amount;
        cin >> amount;
        cout << "Enter Account Number: ";
        int accountNumber;
        cin >> accountNumber;
        Account *account = findAccountByNumber(accounts, count, accountNumber);
        if (account)
        {
            account->deposit(amount);
            cout << "Deposit successful. New balance: " << account->getBalance() << endl;
        }
        else
        {
            cout << "Invalid account type for deposit." << endl;
        }
    }
    static void changePin(Account *accounts[], int count)
    {
        // changing pin number of account
        cout << "Enter Account Number: ";
        int accountNumber;
        cin >> accountNumber;
        Account *account = findAccountByNumber(accounts, count, accountNumber);
        if (account != nullptr)
        {
            cout << "Enter new pin: ";
            int newPin;
            cin >> newPin;
            account->setPin(newPin);
            cout << "Pin changed successfully." << endl;
        }
        else
        {
            cout << "Account not found." << endl;
        }
    }
};
#endif