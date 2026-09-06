#include <iostream>
#include "Student.h"
using namespace std;

// Function to read student details from user
void readStudentDetails(int &id, char name[], int &age, double &m1, double &m2, double &m3) {
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(); // Clear newline from buffer
    
    cout << "Enter Student Name: ";
    cin.getline(name,100,'\n');
    
    cout << "Enter Age: ";
    cin >> age;
    
    cout << "Enter Marks for 3 subjects (m1 m2 m3): "<<endl;
    cin >> m1 >> m2 >> m3;
    cin.ignore(); // Clear newline for next iteration
}

int main() {
    int id, age;
    double m1, m2, m3;
    char name[100];
    
    // Using default constructor and setters
    cout << "Creating Student 1 (Default Constructor + Setters)" << endl;
    readStudentDetails(id, name, age, m1, m2, m3);
    
    Student s1;
    s1.setId(id);
    s1.setName(name);
    s1.setAge(age);
    s1.setM1(m1);
    s1.setM2(m2);
    s1.setM3(m3);
    
    cout << "--- Student 1 Details ---" << endl;
    s1.displayData(); // Display student details
    // Calculate and display average marks
    cout << "Percentage (Average): " << s1.getAvg() << "%" << endl;
    
    // Using parameterized constructor with marks
    cout << "Creating Student 2 (Parameterized Constructor with Marks)" << endl;
    readStudentDetails(id, name, age, m1, m2, m3);
    
    Student s2(id, name, age, m1, m2, m3);
    
    cout << "--- Student 2 Details ---" << endl;
    s2.displayData();
    cout << "Percentage (Average): " << s2.getAvg() << "%" << endl;
    
    // Using parameterized constructor without marks, then setters for marks
    cout << "Creating Student 3 (Parameterized Constructor without Marks + Setters)" << endl;
    readStudentDetails(id, name, age, m1, m2, m3);
    
    Student s3(id, name, age);
    s3.setM1(m1);
    s3.setM2(m2);
    s3.setM3(m3);
    
    cout << "--- Student 3 Details ---" << endl;
    s3.displayData();
    cout << "Percentage (Average): " << s3.getAvg() << "%" << endl;
    
    return 0;
}