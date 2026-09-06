#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

// Default constructor
Student::Student() {
    cout << "Inside default constructor" << endl;
    sid = 0;
    age = 0;
    sname = nullptr;
    m1 = m2 = m3 = 0.0;
}

// Parameterized constructor without marks
Student::Student(int sid, char *name, int age) {
    cout << "Inside parameterized constructor (without marks)" << endl;
    this->sid = sid;
    // allocate memory to store name
    sname = new char[strlen(name) + 1];
    strcpy(sname, name);
    this->age = age;
    m1 = m2 = m3 = 0.0;
}

// Parameterized constructor with marks
Student::Student(int sid, char *name, int age, double marks1, double marks2, double marks3) {
    cout << "Inside parameterized constructor (with marks)" << endl;
    this->sid = sid;
    sname = new char[strlen(name) + 1];
    strcpy(sname, name);
    this->age = age;
    this->m1 = marks1;
    this->m2 = marks2;
    this->m3 = marks3;
}

// getter and setter for sid
int Student::getId() {
    return sid;
}

void Student::setId(int id) {
    sid = id;
}

// getter and setter for sname
char* Student::getName() {
    return sname;
}

void Student::setName(char *nm) {
    if (sname) {
        delete[] sname;
    }
    sname = new char[strlen(nm) + 1];
    strcpy(sname, nm);
}

// getter and setter for age
int Student::getAge() {
    return age;
}

void Student::setAge(int age) {
    this->age = age;
}

// getters for marks
double Student::getM1() {
    return m1;
}

double Student::getM2() {
    return m2;
}

double Student::getM3() {
    return m3;
}

// setters for marks
void Student::setM1(double marks) {
    m1 = marks;
}

void Student::setM2(double marks) {
    m2 = marks;
}

void Student::setM3(double marks) {
    m3 = marks;
}

// Display student data
void Student::displayData() {
    cout << "Name: " << sname << endl;
    cout << "ID: " << sid << endl;
    cout << "Age: " << age << endl;
    cout << "Mark1: " << m1 << " Mark2: " << m2 << " Mark3: " << m3 << endl;
}

// calculate percentage (average of total marks)
double Student::getAvg() {
    double avg = (m1 + m2 + m3) / 3.0;
    return avg;
}

// Destructor
Student::~Student() {
    cout << "Inside Destructor" << endl;
    if (sname) {
        delete[] sname;
    }
}