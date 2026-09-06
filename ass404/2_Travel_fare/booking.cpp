#include <iostream>
#include <cstring>
#include "booking.h"
using namespace std;

Booking::Booking() {
    bookingid = 0;
    source = nullptr;
    destination = nullptr;
    distance = 0.0f;
    fare = 0.0f;
}

Booking::Booking(int bid, char* src, char* dest, float dist, float f) {
    bookingid = bid;
    if (src) {
        source = new char[strlen(src) + 1];
        strcpy(source, src);
    } else {
        source = nullptr;
    }
    if (dest) {
        destination = new char[strlen(dest) + 1];
        strcpy(destination, dest);
    } else {
        destination = nullptr;
    }
    distance = dist;
    fare = f;
}

Booking::Booking(const Booking& other) {
    bookingid = other.bookingid;
    if (other.source) {
        source = new char[strlen(other.source) + 1];
        strcpy(source, other.source);
    } else {
        source = nullptr;
    }
    if (other.destination) {
        destination = new char[strlen(other.destination) + 1];
        strcpy(destination, other.destination);
    } else {
        destination = nullptr;
    }
    distance = other.distance;
    fare = other.fare;
}

Booking::~Booking() {
    if (source) {
        delete[] source;
    }
    if (destination) {
        delete[] destination;
    }
}

int Booking::getBookingId() {
    return bookingid;
}

void Booking::setBookingId(int id) {
    bookingid = id;
}

char* Booking::getSource() {
    return source;
}

void Booking::setSource(char* src) {
    if (source) {
        delete[] source;
    }
    if (src) {
        source = new char[strlen(src) + 1];
        strcpy(source, src);
    } else {
        source = nullptr;
    }
}

char* Booking::getDestination() {
    return destination;
}

void Booking::setDestination(char* dest) {
    if (destination) {
        delete[] destination;
    }
    if (dest) {
        destination = new char[strlen(dest) + 1];
        strcpy(destination, dest);
    } else {
        destination = nullptr;
    }
}

float Booking::getDistance() {
    return distance;
}

void Booking::setDistance(float dist) {
    distance = dist;
}

float Booking::getFare() {
    return fare;
}

void Booking::setFare(float f) {
    fare = f;
}

float Booking::calculateFare() {
    fare = distance * 10.0f;
    return fare;
}

float Booking::calculateFare(int vehicleType) {
    float vehicleMultiplier = 1.0f;
    switch (vehicleType) {
        case 1: vehicleMultiplier = 1.0f; break;
        case 2: vehicleMultiplier = 1.5f; break;
        case 3: vehicleMultiplier = 2.0f; break;
        case 4: vehicleMultiplier = 2.5f; break;
        default: vehicleMultiplier = 1.0f;
    }
    fare = distance * 10.0f * vehicleMultiplier;
    return fare;
}

float Booking::calculateFare(int vehicleType, int passengers) {
    float vehicleMultiplier = 1.0f;
    switch (vehicleType) {
        case 1: vehicleMultiplier = 1.0f; break;
        case 2: vehicleMultiplier = 1.5f; break;
        case 3: vehicleMultiplier = 2.0f; break;
        case 4: vehicleMultiplier = 2.5f; break;
        default: vehicleMultiplier = 1.0f;
    }
    fare = distance * 10.0f * vehicleMultiplier * passengers;
    return fare;
}

float Booking::calculateFare(int vehicleType, int passengers, float serviceCharges) {
    float vehicleMultiplier = 1.0f;
    switch (vehicleType) {
        case 1: vehicleMultiplier = 1.0f; break;
        case 2: vehicleMultiplier = 1.5f; break;
        case 3: vehicleMultiplier = 2.0f; break;
        case 4: vehicleMultiplier = 2.5f; break;
        default: vehicleMultiplier = 1.0f;
    }
    fare = distance * 10.0f * vehicleMultiplier * passengers + serviceCharges;
    return fare;
}

void Booking::display() {
    cout << "Booking ID: " << bookingid << endl;
    cout << "Source: " << (source ? source : "N/A") << endl;
    cout << "Destination: " << (destination ? destination : "N/A") << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Fare: " << fare << endl;
}

ostream& operator<<(ostream& os, const Booking& b) {
    os << "Booking ID: " << b.bookingid << endl;
    os << "Source: " << (b.source ? b.source : "N/A") << endl;
    os << "Destination: " << (b.destination ? b.destination : "N/A") << endl;
    os << "Distance: " << b.distance << " km" << endl;
    os << "Fare: " << b.fare << endl;
    return os;
}

istream& operator>>(istream& is, Booking& b) {
    int id;
    char src[100], dest[100];
    float dist;

    cout << "Enter Booking ID: ";
    is >> id;
    cout << "Enter Source: ";
    is.ignore();
    is.getline(src, 100);
    cout << "Enter Destination: ";
    is.getline(dest, 100);
    cout << "Enter Distance (km): ";
    is >> dist;

    b.setBookingId(id);
    b.setSource(src);
    b.setDestination(dest);
    b.setDistance(dist);

    return is;
}