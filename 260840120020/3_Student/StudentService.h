#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

class StudentService
{
public:
    static bool addStudent(Student **arr, int &count, int max)
    {
        int pid, age;
        double m1, m2, m3;
        // char *name;
        char nm[100];

        // accept student details from user
        cout << "Enter pid" << endl;
        cin >> pid;
        cout << "Enter age" << endl;
        cin >> age;
        cout << "Enter name" << endl;
        cin >> nm;
        cout << "Enter marks of m1,m2,m3: " << endl;
        cin >> m1 >> m2 >> m3;

        // name = new char[strlen(nm)+1];
        // strcpy(name,nm);
        // accept name with spaces
        // cin.getline(nm,'\n');

        if (count < max)
        {
            arr[count] = new Student(pid, nm, age, m1, m2, m3);
            count++;
            return true;
        }
        return false;
    }
    // static bool addStudent(Student **arr, int &count, int max)
    // {
    //     if (count + 1 > max)
    //     {
    //         return false;
    //     }
    //     arr[++count] = new Student();
    //     int sid, age;
    //     char name[100];
    //     double m1, m2, m3;
    //     cout << "enter student id" << endl;
    //     cin >> sid;
    //     arr[count]->setId(sid);

    //     cout << "enter student Name" << endl;
    //     cin >> name;
    //     arr[count]->setName(name);

    //     cout << "enter student Age" << endl;
    //     cin >> age;
    //     arr[count]->setAge(age);

    //     cout << "Enter marks of m1,m2,m3: " << endl;
    //     cin >> m1 >> m2 >> m3;
    //     arr[count]->setM1(m1);
    //     arr[count]->setM2(m2);
    //     arr[count]->setM3(m3);
    //     cout<<count;

    //     return true;
    // }
    static Student *searchById(Student **arr, int &count, int id)
    {
        // cout<<count;
        for (int i = 0; i < count; i++)
        {
            if (arr[i]->getId() == id)
            {
                return arr[i];
            }
        }
        return NULL;
    }
    static Student *searchByName(Student **arr, int &count, char name[])
    {
        for (int i = 0; i < count; i++)
        {
            if (!strcmp(arr[i]->getName(), name))
            {
                return arr[i];
            }
        }
        return NULL;
    }
    static bool modifyById(Student **arr, int count, int id, char nm[], int age)
    {
        Student *stud = searchById(arr, count, id);
        if (stud == NULL)
            return false;
        stud->setName(nm);
        stud->setAge(age);
        return true;
    }
    static void displayAll(Student **arr, int &count)
    {

        for (int i = 0; i < count; i++)
        {
            arr[i]->displayData();
        }
    }
    static void sortByName(Student **arr, int &count)
    {

        // selection sort
        Student *temp;
        int comp; //
        for (int i = 0; i < count; i++)
        {

            int min_index = i; // assume first element is minimum

            for (int j = i + 1; j < count - 1; j++)
            {
                // compare the names of students
                comp = strcmp(arr[min_index]->getName(), arr[j]->getName());

                if (comp > 0)
                {
                    // swaping the elements
                    *temp = *arr[min_index];
                    *arr[min_index] = *arr[j];
                    *arr[j] = *temp;
                    // update the min_index
                    min_index = j;
                }
            }
        }
    }
    static bool deleteById(Student **arr, int &count, int id)
    {
        // search the student with given id
        for (int i = 0; i < count; i++)
        {
            if (arr[i]->getId() == id)
            {
                // delete the student object
                delete arr[i];
                // shift the elements to left
                for (int j = i; j < count - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                // decrement the count and set the last element to NULL
                arr[--count] = NULL;
                return true;
            }
        }
        return false;
    }
};
#endif