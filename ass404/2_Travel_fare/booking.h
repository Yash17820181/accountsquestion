#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
using namespace std;

class Booking {
    private:
        int bookingid;
        char* source;
        char* destination;
        float distance;
        float fare;
    public:
        // Default constructor
        Booking();
        // Parameterized constructor with default values
        Booking(int bid, char* src, char* dest, float dist = 0.0f, float f = 0.0f);
        // Copy constructor
        Booking(const Booking& other);
        // Destructor
        ~Booking();
        // Getter and setter methods
        int getBookingId();
        void setBookingId(int id);
        char* getSource();
        void setSource(char* src);
        char* getDestination();
        void setDestination(char* dest);
        float getDistance();
        void setDistance(float dist);
        float getFare();
        void setFare(float f);
        // Calculate fare overloads
        float calculateFare();                          // Based on distance only
        float calculateFare(int vehicleType);           // Based on distance and vehicle type
        float calculateFare(int vehicleType, int passengers); // Based on distance, vehicle type, passengers
        float calculateFare(int vehicleType, int passengers, float serviceCharges); // Premium booking
        // Display method
        void display();
        // Friend operators for I/O
        friend ostream& operator<<(ostream& os, const Booking& b);
        friend istream& operator>>(istream& is, Booking& b);
};

#endif