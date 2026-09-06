#include <iostream>
#include <cstring>
#include "Friend.h"
using namespace std;

// Default constructor
Friend::Friend() {
    cout << "Inside default constructor" << endl;
}

// Parameterized constructor
Friend::Friend(int id, char* name, char* email, char* bdate, char* address) {
    cout << "Inside parameterized constructor" << endl;
    this->id = id;
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    
    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);
    
    this->bdate = new char[strlen(bdate) + 1];
    strcpy(this->bdate, bdate);
    
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

// Copy constructor (deep copy)
Friend::Friend(const Friend& other) {
    cout << "Inside copy constructor" << endl;
    id = other.id;
    
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    } else {
        name = nullptr;
    }
    
    if (other.email) {
        email = new char[strlen(other.email) + 1];
        strcpy(email, other.email);
    } else {
        email = nullptr;
    }
    
    if (other.bdate) {
        bdate = new char[strlen(other.bdate) + 1];
        strcpy(bdate, other.bdate);
    } else {
        bdate = nullptr;
    }
    
    if (other.address) {
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
    } else {
        address = nullptr;
    }
    
    hobbyCount = other.hobbyCount;
    if (other.hobbies && hobbyCount > 0) {
        hobbies = new char*[hobbyCount];
        for (int i = 0; i < hobbyCount; i++) {
            hobbies[i] = new char[strlen(other.hobbies[i]) + 1];
            strcpy(hobbies[i], other.hobbies[i]);
        }
    } else {
        hobbies = nullptr;
    }
    
    mobileCount = other.mobileCount;
    if (other.mobileNumbers && mobileCount > 0) {
        mobileNumbers = new char*[mobileCount];
        for (int i = 0; i < mobileCount; i++) {
            mobileNumbers[i] = new char[strlen(other.mobileNumbers[i]) + 1];
            strcpy(mobileNumbers[i], other.mobileNumbers[i]);
        }
    } else {
        mobileNumbers = nullptr;
    }
}

// Assignment operator (deep copy)
Friend& Friend::operator=(const Friend& other) {
    cout << "Inside assignment operator" << endl;
    if (this == &other) return *this;
    
    // Clean up existing memory
    if (name) delete[] name;
    if (email) delete[] email;
    if (bdate) delete[] bdate;
    if (address) delete[] address;
    
    if (hobbies) {
        for (int i = 0; i < hobbyCount; i++) {
            delete[] hobbies[i];
        }
        delete[] hobbies;
    }
    
    if (mobileNumbers) {
        for (int i = 0; i < mobileCount; i++) {
            delete[] mobileNumbers[i];
        }
        delete[] mobileNumbers;
    }
    
    // Copy new data
    id = other.id;
    
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    } else {
        name = nullptr;
    }
    
    if (other.email) {
        email = new char[strlen(other.email) + 1];
        strcpy(email, other.email);
    } else {
        email = nullptr;
    }
    
    if (other.bdate) {
        bdate = new char[strlen(other.bdate) + 1];
        strcpy(bdate, other.bdate);
    } else {
        bdate = nullptr;
    }
    
    if (other.address) {
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
    } else {
        address = nullptr;
    }
    
    hobbyCount = other.hobbyCount;
    if (other.hobbies && hobbyCount > 0) {
        hobbies = new char*[hobbyCount];
        for (int i = 0; i < hobbyCount; i++) {
            hobbies[i] = new char[strlen(other.hobbies[i]) + 1];
            strcpy(hobbies[i], other.hobbies[i]);
        }
    } else {
        hobbies = nullptr;
    }
    
    mobileCount = other.mobileCount;
    if (other.mobileNumbers && mobileCount > 0) {
        mobileNumbers = new char*[mobileCount];
        for (int i = 0; i < mobileCount; i++) {
            mobileNumbers[i] = new char[strlen(other.mobileNumbers[i]) + 1];
            strcpy(mobileNumbers[i], other.mobileNumbers[i]);
        }
    } else {
        mobileNumbers = nullptr;
    }
    
    return *this;
}

// Getters and setters
int Friend::getId() {
    return id;
}

void Friend::setId(int id) {
    this->id = id;
}

char* Friend::getName() {
    return name;
}

void Friend::setName(char* nm) {
    if (name) delete[] name;
    name = new char[strlen(nm) + 1];
    strcpy(name, nm);
}

char* Friend::getEmail() {
    return email;
}

void Friend::setEmail(char* em) {
    if (email) delete[] email;
    email = new char[strlen(em) + 1];
    strcpy(email, em);
}

char* Friend::getBdate() {
    return bdate;
}

void Friend::setBdate(char* bd) {
    if (bdate) delete[] bdate;
    bdate = new char[strlen(bd) + 1];
    strcpy(bdate, bd);
}

char* Friend::getAddress() {
    return address;
}

void Friend::setAddress(char* addr) {
    if (address) delete[] address;
    address = new char[strlen(addr) + 1];
    strcpy(address, addr);
}

// Hobbies
char** Friend::getHobbies() {
    return hobbies;
}

int Friend::getHobbyCount() {
    return hobbyCount;
}

void Friend::addHobby(char* hobby) {
    char** newHobbies = new char*[hobbyCount + 1];
    for (int i = 0; i < hobbyCount; i++) {
        newHobbies[i] = hobbies[i];
    }
    newHobbies[hobbyCount] = new char[strlen(hobby) + 1];
    strcpy(newHobbies[hobbyCount], hobby);
    
    if (hobbies) {
        delete[] hobbies;
    }
    hobbies = newHobbies;
    hobbyCount++;
}

// Mobile numbers
char** Friend::getMobileNumbers() {
    return mobileNumbers;
}

int Friend::getMobileCount() {
    return mobileCount;
}

void Friend::addMobile(char* mobile) {
    char** newMobiles = new char*[mobileCount + 1];
    for (int i = 0; i < mobileCount; i++) {
        newMobiles[i] = mobileNumbers[i];
    }
    newMobiles[mobileCount] = new char[strlen(mobile) + 1];
    strcpy(newMobiles[mobileCount], mobile);
    
    if (mobileNumbers) {
        delete[] mobileNumbers;
    }
    mobileNumbers = newMobiles;
    mobileCount++;
}

// Display friend data
void Friend::displayData() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Birth Date: " << bdate << endl;
    cout << "Address: " << address << endl;
    
    cout << "Hobbies (" << hobbyCount << "): ";
    for (int i = 0; i < hobbyCount; i++) {
        cout << hobbies[i];
        if (i < hobbyCount - 1) cout << ", ";
    }
    cout << endl;
    
    cout << "Mobile Numbers (" << mobileCount << "): ";
    for (int i = 0; i < mobileCount; i++) {
        cout << mobileNumbers[i];
        if (i < mobileCount - 1) cout << ", ";
    }
    cout << endl;
}

// Destructor
Friend::~Friend() {
    cout << "Inside Destructor" << endl;
    if (name) delete[] name;
    if (email) delete[] email;
    if (bdate) delete[] bdate;
    if (address) delete[] address;
    
    if (hobbies) {
        for (int i = 0; i < hobbyCount; i++) {
            delete[] hobbies[i];
        }
        delete[] hobbies;
    }
    
    if (mobileNumbers) {
        for (int i = 0; i < mobileCount; i++) {
            delete[] mobileNumbers[i];
        }
        delete[] mobileNumbers;
    }
}