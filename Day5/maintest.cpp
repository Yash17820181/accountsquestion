#include <iostream>
#include "account.h"
#include "curr_acc.h"
#include "sav_acc.h"
#include "demat_acc.h"
#include "share.h"
#include "accservices.h"

using namespace std;

// maximum number of accounts
int MAX_ACCOUNTS = 100;

// inttializing account counts to 0
int CurrentAccount::currentAccountCount = 0;
int SavingAccount::SavingsAccountCount = 0;
int DematAccount::DematAccountCount = 0;

int main()
{   
    // Choice variable to store user input for menu selection
    int choice = 0;
    // storing account type selected by user (1: Current, 2: Savings, 3: Demat)
    int accountType = 0;

    // Count number of accounts created
    static int count = 0;

    // storing all accounts
    Account *account[MAX_ACCOUNTS];
    do
    {
        // menu for selection
        cout << "1. Add New Account" << endl;
        cout << "2. Display Account Details By ID" << endl;
        cout << "3. Close Account" << endl;
        cout << "4. Count Type of Accounts" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Deposit Money" << endl;
        cout << "7. Change pin" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // add new account
            AccountService::addAccount(account, MAX_ACCOUNTS, count);
            break;
        case 2: // Display all acccounts with details
            AccountService::displayAllAccountDetails(account, count);
            break;
        case 3:
            // delete account
            AccountService::closeAccount(account, count);
            break;
        case 4:
            // display number of account types with count
            cout << "Current Account Count: " << CurrentAccount::getCurrentAccountCount() << endl;
            cout << "Saving Account Count: " << SavingAccount::getSavingsAccountCount() << endl;
            cout << "Demat Account Count: " << DematAccount::getDematAccountCount() << endl;
            break;
        case 5:
            // withdrawing money 
            AccountService::withdrawMoney(account, count);
            break;
        case 6: // desposit money
            AccountService::depositMoney(account, count);
            break;
        case 7:
            // change pin
            AccountService::changePin(account, count);
            break;
        case 8:
            // Exit
            cout << "Thank you for using our services!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);
    // free allocated memory
    for (int i = 0; i < count; i++)
    {
        delete account[i];
    }
    return 0;
}