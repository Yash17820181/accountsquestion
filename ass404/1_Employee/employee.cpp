#include <iostream>
#include <cstring>
#include "employee.h"
using namespace std;

Employee::Employee() {}
Employee::Employee(char name[], int empid, double basic_salary)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->empid = empid;
    this->basic_salary = basic_salary;
}
Employee::~Employee()
{   
    if(name){
        delete[] name;
    }
}
// getter and setter methods
char *Employee::getName()
{
    return name;
}
void Employee::setName(char *name)
{
    delete[] this->name; // free the old memory
    this->name = new char[strlen(name) + 1]; // allocate new memory
    strcpy(this->name, name); // copy the new name
}
int Employee::getEmpid()
{
    return empid;
}
void Employee::setEmpid(int empid)
{
    this->empid = empid;
}
double Employee::getBasicSalary()
{
    return basic_salary;
}
void Employee::setBasicSalary(double basic_salary)
{
    this->basic_salary = basic_salary;
}
// Method to display employee details
void Employee::display()
{
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << empid << endl;
    cout << "Basic Salary: " << basic_salary << endl;
}
// Method to calculate salary

// no parameters for basic salary
double Employee::calculateSalary()
{
    return basic_salary;
}
// method to calculate salary with bonus
double Employee::calculateSalary(double bonus)
{
    return basic_salary + bonus;
}
// method to calculate salary with hours worked and hourly rate
double Employee::calculateSalary(double hours_worked, double hourly_rate)
{
    return hours_worked * hourly_rate;
}
