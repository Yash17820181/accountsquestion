#ifndef EMPLOYEE_SERVICES_H
#define EMPLOYEE_SERVICES_H

#include <iostream>
#include <cstring>
#include "employee.h"
using namespace std;

class EmployeeServices
{
public:
    // function to add employee
    static bool addEmployee(Employee *emp[], int &count, int max)
    {

        int id;
        char name[50];

        double basic_salary, bonus;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore(); // to ignore the newline character left in the buffer
        cin.getline(name, 50);
        cout << "Enter Basic Salary: ";
        cin >> basic_salary;

        // create a new employee object and add it to the array
        if (count < max)
        {
            emp[count] = new Employee(name, id, basic_salary);
            count++;
            // display the details of the newly added employee
            cout << emp[count-1];
            return true;
        }
        return false;
    }

    // function to display employee details
    static void displayAllEmployee(Employee *emp[], int count)
    {
        for (int i = 0; i < count; i++)
        {
            emp[i]->display();
            cout << "---------------------------" << endl;
        }
    }
    static Employee *getEmployeeById(Employee *emp[], int count, int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (emp[i]->getEmpid() == id)
            {
                return emp[i];
            }
        }
        return nullptr;
    }
    static double getSalary(Employee *emp[], int count, int id)
    {
        Employee *employee = getEmployeeById(emp, count, id);
        if (employee != nullptr)
        {
            return employee->getBasicSalary();
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
            return -1; // or some other error value
        }
    }
    static double getSalary(Employee *emp[], int count, int id, double bonus)
    {
        Employee *employee = getEmployeeById(emp, count, id);
        if (employee != nullptr)
        {
            return employee->calculateSalary(bonus);
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
            return -1; // or some other error value
        }
    }
    static double getSalary(Employee *emp[], int count, int id, double hours_worked, double hourly_rate)
    {
        Employee *employee = getEmployeeById(emp, count, id);
        if (employee != nullptr)
        {
            return employee->calculateSalary(hours_worked, hourly_rate);
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
            return -1; // or some other error value
        }
    }
};
#endif