#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;
// creating class students
Student::Student()
{
	cout << "Inside default constructor" << endl;
}
Student::Student(int sid,char *name, int age){
   cout<<"In Person parametrised constructor"<<endl;
   this->sid=sid;
   //allocate memory to store name
   sname=new char[strlen(name)+1];
   strcpy(sname,name); 
   this->age=age;  
}
// Student::Student(int sid, char *sname, int age)
// {

// 	cout << "Inside paramerterised constructor" << endl;
// 	this->sid = sid;
// 	this->sname = sname;
// 	this->age = age;
// }

Student::Student(int sid, char *name, int age, double marks1, double marks2, double marks3)
{

	cout << "Inside paramerterised constructor" << endl;
	this->sid = sid;
	sname=new char[strlen(name)+1];
	strcpy(sname,name); 
	this->age = age;
	this->m1 = marks1;
	this->m2 = marks2;
	this->m3 = marks3;
}
// getter and setter for sid
int Student::getId()
{
	return sid;
}
void Student::setId(int id)
{
	sid = id;
}
// getter and setter for sname
char* Student::getName()
{
	return sname;
}
void Student::setName(char *nm){
     if(sname)
       delete[] sname;
     sname=new char[strlen(nm)+1];
     strcpy(sname,nm);
  
}
// getter and setter for age
int Student::getAge()
{
	return age;
}
void Student::setAge(int age)
{
	this->age = age;
}
// getters for marks
double Student::getM1()
{
	return m1;
}
double Student::getM2()
{
	return m2;
}
double Student::getM3()
{
	return m3;
}
// setters for marks
void Student::setM1(double marks)
{
	m1 = marks;
}
void Student::setM2(double marks)
{
	m2 = marks;
}
void Student::setM3(double marks)
{
	m3 = marks;
}
// Display student data
void Student::displayData()
{
	cout << "Name: " << sname << endl;
	cout << "ID: " << sid << endl;
	cout << "Age: " << age << endl;
	cout << "Mark1: " << m1 << " Mark2: " << m2 << " Mark3: " << m3 << endl;
}
// calculate average of total marks
double Student::getAvg()
{
	double avg = (m1 + m2 + m3) / 3.0;
	return avg;
}

// calculate total gpa
double Student::getGPA(){
	// GPA calculation based on marks
	double gpa=(1.0/3.0)*m1+(1.0/2.0)*m2+(1.0/4.0)*m3;
	return gpa;
}

// Destructor method
Student::~Student()
{
	cout << "Inside Destructor" << endl;
	if(sname){
		delete[] sname;
	}
}