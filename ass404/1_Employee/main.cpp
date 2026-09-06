// main file for testing
#include <iostream>
#include <cstring>
#include "employee.h"
#include "employeeservices.h"
using namespace std;

// output stream
ostream &operator<<(ostream &os, Employee& emp)
{
    emp.display();
    return os;
}

// input stream
istream &operator>>(istream &is, Employee &emp)
{

    int id;
    char name[50];
    double basic_salary;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Name: ";
    cin.ignore(); // to ignore the newline character left in the buffer
    cin.getline(name, 50);
    cout << "Enter Basic Salary: ";
    cin >> basic_salary;
    
    emp.setEmpid(id);
    emp.setName(name);
    emp.setBasicSalary(basic_salary);
    return is;
}

int main()
{
    // using overloaded operators
    Employee employee;

    // using operator << with for input of object
    cin >> employee;

    //display object using << operator with cout
    cout << employee << endl;
    return 0;
}
