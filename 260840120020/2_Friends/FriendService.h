#ifndef FRIEND_SERVICE_H
#define FRIEND_SERVICE_H

#include <iostream>
#include <cstring>
#include "Friend.h"
using namespace std;

class FriendService {
public:
    static bool addFriend(Friend** arr, int& count, int max) {
        int fid;
        char nm[100], email[100], bdate[50], address[200];
        char hobby[100], mobile[20];
        char choice;
        int hobbyCount = 0, mobileCount = 0;
        
        // Accept friend details from user
        cout << "Enter Friend ID: ";
        cin >> fid;
        cin.ignore();
        
        cout << "Enter Name: ";
        cin.getline(nm, 100);
        
        cout << "Enter Email: ";
        cin.getline(email, 100);
        
        cout << "Enter Birth Date (dd/mm/yyyy): ";
        cin.getline(bdate, 50);
        
        cout << "Enter Address: ";
        cin.getline(address, 200);
        
        if (count >= max) {
            return false;
        }
        
        // Create friend object
        arr[count] = new Friend(fid, nm, email, bdate, address);
        
        // Add hobbies
        cout << "Add hobby :" << endl;
        cin.getline(hobby, 100);
        arr[count]->addHobby(hobby);
        hobbyCount++;

        // Add mobile numbers
        cout << "Add mobile number:" << endl;
        cin.getline(mobile, 20);
        arr[count]->addMobile(mobile);
        mobileCount++;
        
        count++;
        return true;
    }
    
    static Friend* searchById(Friend** arr, int count, int id) {
        for (int i = 0; i < count; i++) {
            if (arr[i]->getId() == id) {
                return arr[i];
            }
        }
        return NULL;
    }
    
    static Friend* searchByName(Friend** arr, int count, char name[]) {
        for (int i = 0; i < count; i++) {
            if (strcmp(arr[i]->getName(), name) == 0) {
                return arr[i];
            }
        }
        return NULL;
    }
    
    static void displayByHobby(Friend** arr, int count, char hobby[]) {
        for (int i = 0; i < count; i++) {
            char** hobbies = arr[i]->getHobbies();
            int hobbyCount = arr[i]->getHobbyCount();
            for (int j = 0; j < hobbyCount; j++) {
                if (strcmp(hobbies[j], hobby) == 0) {
                    cout << "\nFriends with hobby '" << hobby << "':" << endl;
                    arr[i]->displayData();
                    break; // No need to check other hobbies for this friend
                }
            }
        }
    }
    
    static void displayAll(Friend** arr, int count) {
        if (count == 0) {
            cout << "No friends to display." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "Friend " << (i + 1) << ":" << endl;
            arr[i]->displayData();
            cout << endl;   
        }
    }

    static bool addHobbyToFriend(Friend** arr, int count, int id, char hobby[]) {
        for (int i = 0; i < count; i++) {
            if (arr[i]->getId() == id) {
                arr[i]->addHobby(hobby);
                return true;
            }
        }
        return false;
    }

    static bool addMobileToFriend(Friend** arr, int count, int id, char mobile[]) {
        for (int i = 0; i < count; i++) {
            if (arr[i]->getId() == id) {
                arr[i]->addMobile(mobile);
                return true;
            }
        }
        return false;
    }
};

#endif