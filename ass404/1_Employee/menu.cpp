//Menu driven class allocation
#include <iostream>
#include <cstring>
#include "employee.h"
#include "employeeservices.h"
using namespace std;

// maximum number of employees
int MAX = 10;

int main()
{
    // array of employee pointers
    Employee *emp[MAX];
    // count of employees
    int count = 0;
    bool status;
    // employee details
    int id;
    char name[50];
    double salary, bonus, hours_worked, hourly_rate;

    // choice to switch cases
    int choice = 0;
    do
    {
        cout << "1. Create Employee" << endl;
        cout << "2. Display Employee Details" << endl;
        cout << "3. Get Basic Salary" << endl;
        cout << "4. Calculate Salary with bonus" << endl;
        cout << "5. Calculate Salary with hours worked and hourly rate" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            status = EmployeeServices::addEmployee(emp, count, MAX);
            if (!status)
            {
                cout << "Cannot add more employees!" << endl;
            }
            else
            {
                cout << "Employee created successfully!" << endl;
            }
            break;
        case 2:
            EmployeeServices::displayAllEmployee(emp, count);
            break;
        case 3:
            cout << "Enter Employee ID: ";
            cin >> id;
            salary = EmployeeServices::getSalary(emp, count, id);
            cout << "Calculated Salary: " << salary << endl;
            break;
        case 4:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Bonus: ";
            cin >> bonus;
            salary = EmployeeServices::getSalary(emp, count, id, bonus);
            cout << "Calculated Salary: " << salary << endl;
            break;
        case 5:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Hours Worked: ";
            cin >> hours_worked;
            cout << "Enter Hourly Rate: ";
            cin >> hourly_rate;
            salary = EmployeeServices::getSalary(emp, count, id, hours_worked, hourly_rate);
            cout << "Calculated Salary: " << salary << endl;
            break;
        case 6:
            cout << "Exiting the program." << endl;
            // free the memory allocated for employees
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice!=6);
    
    // clearing memory
    for (int i = 0; i < count; i++)
    {
        delete emp[i];
    }
    return 0;
}