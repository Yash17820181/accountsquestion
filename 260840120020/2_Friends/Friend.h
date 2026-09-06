#ifndef FRIEND_H
#define FRIEND_H

class Friend {
private:
    int id;
    char* name;
    char** hobbies;
    int hobbyCount=0;
    char** mobileNumbers;
    int mobileCount=0;
    char* email;
    char* bdate;
    char* address;

public:
    // Default constructor
    Friend();
    
    // Parameterized constructor
    Friend(int id, char* name, char* email, char* bdate, char* address);
    
    // Copy constructor
    Friend(const Friend& other);
    
    // Assignment operator
    Friend& operator=(const Friend& other);
    
    // Getters and setters
    int getId();
    void setId(int id);
    
    char* getName();
    void setName(char* name);
    
    char* getEmail();
    void setEmail(char* email);
    
    char* getBdate();
    void setBdate(char* bdate);
    
    char* getAddress();
    void setAddress(char* address);
    
    // Hobbies
    char** getHobbies();
    int getHobbyCount();
    void addHobby(char* hobby);
    
    // Mobile numbers
    char** getMobileNumbers();
    int getMobileCount();
    void addMobile(char* mobile);
    
    // Display friend data
    void displayData();
    
    // Destructor
    ~Friend();
};

#endif