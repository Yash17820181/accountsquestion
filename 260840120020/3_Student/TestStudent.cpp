#include <iostream>
#include "Student.h"
#include "StudentService.h"
using namespace std;

int main()
{
	const int MAX = 100;
	Student *arr[MAX];
	int count = 0, id, age;
	char nm[10];
	Student *p = NULL;
	int choice = 0;
	bool status;
	do
	{
		cout << "1. Add Student\n2. Search by id\n3. search by Name\n4. modify Student\n";
		cout << "5. display all\n6. sort by name\n7. delete by id\n0. exit\nchoice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//add student
			status = StudentService::addStudent(arr, count, MAX);
			if (status)
			{ // status==true.
				cout << "Added successfully" << endl;
			}
			else
			{
				cout << "Limit is over" << endl;
			}
			break;
		case 2:
			//search by id
			cout << "enter id to search\n";
			cin >> id;
			p = StudentService::searchById(arr, count, id);
			if (p != NULL)
			{
				p->displayData();
			}
			else
			{
				cout << "Not found" << endl;
			}
			break;
		case 3:
		    //search by name
		    cout << "enter name to search\n";
			cin >> nm;
			p = StudentService::searchByName(arr, count, nm);
			if (p != NULL)
			{
				p->displayData();
			}
			else
			{
				cout << "Not found" << endl;
			}
			break;
		case 4:
		//modify Student
			cout << "Enter id to modify" << endl;
			cin >> id;
			cout << "enter new name" << endl;
			cin >> nm;
			cout << "Enter new age" << endl;
			cin >> age;
			status = StudentService::modifyById(arr, count, id, nm, age);
			if (status)
			{
				cout << "Modification done" << endl;
			}
			else
			{
				cout << id << " not found" << endl;
			}
			break;
		case 5:
		//display all objects
			StudentService::displayAll(arr, count);
			break;
		case 6:
		    //sort by name
            StudentService::sortByName(arr,count);
			break;
		case 7:
		//delete by id
			cout << "Enter id : " << endl;
			cin >> id;
			status = StudentService::deleteById(arr, count, id);
			if (status)
			{
				cout << "Deleted successfully" << endl;
			}
			else
			{
				cout << "Not Found" << endl;
			}
			break;
		case 0:
		//exit
			cout << "Thank you for visiting ......."<<endl;
			break;
		default:
			cout << "Invalid choice (0....7)" << endl;
			break;
		}
		
	} while (choice != 0);
	delete p;
	delete[] nm;
	return 0;
}