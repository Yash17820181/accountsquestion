#include <iostream>
#include "booking.h"
using namespace std;

int main() {
    cout << "=== Testing Booking Class ===" << endl << endl;

    cout << "--- Test 1: Default Constructor and Input/Output Operators ---" << endl;
    Booking b1;
    cout << "Enter booking details:" << endl;
    cin >> b1;
    cout << "\nBooking details entered:" << endl;
    cout << b1 << endl;

    cout << "--- Test 2: Parameterized Constructor ---" << endl;
    Booking b2(102, "Mumbai", "Delhi", 1400.0f);
    cout << "Booking created with parameterized constructor:" << endl;
    cout << b2 << endl;

    cout << "--- Test 3: Copy Constructor ---" << endl;
    Booking b3 = b2;
    cout << "Booking copied from b2:" << endl;
    cout << b3 << endl;

    cout << "--- Test 4: calculateFare() - Distance only ---" << endl;
    b2.calculateFare();
    cout << "Fare (distance only): " << b2.getFare() << endl;

    cout << "--- Test 5: calculateFare(int vehicleType) ---" << endl;
    b2.calculateFare(2);
    cout << "Fare (distance + vehicle type 2): " << b2.getFare() << endl;

    cout << "--- Test 6: calculateFare(int vehicleType, int passengers) ---" << endl;
    b2.calculateFare(3, 4);
    cout << "Fare (distance + vehicle type 3 + 4 passengers): " << b2.getFare() << endl;

    cout << "--- Test 7: calculateFare(int vehicleType, int passengers, float serviceCharges) ---" << endl;
    b2.calculateFare(4, 2, 500.0f);
    cout << "Fare (premium: distance + vehicle type 4 + 2 passengers + 500 service): " << b2.getFare() << endl;

    cout << "\n=== All Tests Completed ===" << endl;
    return 0;
}