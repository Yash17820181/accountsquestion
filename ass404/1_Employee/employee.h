#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
    private:
        char* name = nullptr;
        int empid;
        double basic_salary;
    public:
        // Default constructor
        Employee();
        // Parameterized constructor
        Employee(char* name, int empid, double basic_salary);
        // Destructor
        ~Employee();
        //getter and setter methods
        char* getName();
        void setName(char* name);
        int getEmpid();
        void setEmpid(int empid);
        double getBasicSalary();
        void setBasicSalary(double basic_salary);
        // Method to display employee details
        void display();
        //calculate salary method
        double calculateSalary();
        double calculateSalary(double bonus);
        double calculateSalary(double hours_worked, double hourly_rate);

        friend ostream& operator<<(ostream& os, Employee& emp);
        friend istream& operator>>(istream& is, Employee& emp);
};
#endif