#include <iostream>
#include "Friend.h"
#include "FriendService.h"
using namespace std;

int main() {
    const int MAX = 100;
    Friend* arr[MAX];
    int count = 0;
    int choice = 0;
    int id;
    char nm[100];
    char hobby[100];
    Friend* p = NULL;
    
    do {
        cout << "1. Add Friend" << endl;
        cout << "2. Display All Friends" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Search by Name" << endl;
        cout << "5. Display Friends by Hobby" << endl;
        cout << "6. Add Hobby to Friend" << endl;
        cout << "7. Add Mobile Number to Friend" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                // Add friend
                bool status = FriendService::addFriend(arr, count, MAX);
                if (status) {
                    cout << "\nFriend added successfully!" << endl;
                } else {
                    cout << "\nFriend limit reached. Cannot add more." << endl;
                }
                break;
            }
            case 2: {
                // Display all friends
                FriendService::displayAll(arr, count);
                break;
            }
            case 3: {
                // Search by ID
                cout << "Enter ID to search: ";
                cin >> id;
                p = FriendService::searchById(arr, count, id);
                if (p != NULL) {
                    cout << "\nFriend found:" << endl;
                    p->displayData();
                } else {
                    cout << "Friend with ID " << id << " not found." << endl;
                }
                break;
            }
            case 4: {
                // Search by name
                cin.ignore();
                cout << "Enter name to search: ";
                cin.getline(nm, 100);
                p = FriendService::searchByName(arr, count, nm);
                if (p != NULL) {
                    cout << "Friend found:" << endl;
                    p->displayData();
                } else {
                    cout << "Friend with name '" << nm << "' not found." << endl;
                }
                break;
            }
            case 5: {
                // Display friends by hobby
                cin.ignore();
                cout << "Enter hobby to search: ";
                cin.getline(hobby, 100);
                FriendService::displayByHobby(arr, count, hobby);
                break;
            }
            case 6: {
                // Add hobby to friend
                cin.ignore();
                cout << "Enter Friend ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Hobby: ";
                cin.getline(hobby, 100);
                bool status = FriendService::addHobbyToFriend(arr, count, id, hobby);
                if (status) {
                    cout << "Hobby added successfully!" << endl;
                } else {
                    cout << "Friend with ID " << id << " not found." << endl;
                }
                break;
            }
            case 7: {
                // Add mobile number to friend
                cin.ignore();
                cout << "Enter Friend ID: ";
                cin >> id;
                cin.ignore();
                char mobile[20];
                cout << "Enter Mobile Number: ";
                cin.getline(mobile, 20);
                bool status = FriendService::addMobileToFriend(arr, count, id, mobile);
                if (status) {
                    cout << "Mobile number added successfully!" << endl;
                } else {
                    cout << "Friend with ID " << id << " not found." << endl;
                }
                break;
            }
            case 0: {
                // Exit
                cout << "Thank you for using Friend Management System!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please enter 0-7." << endl;
                break;
            }
        }
    } while (choice != 0);
    
    // Clean up memory
    for (int i = 0; i < count; i++) {
        delete arr[i];
    }
    
    return 0;
}