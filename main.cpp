#include <iostream>
#include <iomanip>
#include <ctime>   
using namespace std;

bool isPeakHour(int hour) {
    return ((hour >= 7 && hour <= 9) ||   
            (hour >= 12 && hour <= 14) || 
            (hour >= 17 && hour <= 19));  
}

int main() {
    int service;
    double distance, fare = 0.0;

    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;   // 0-23

    // interface for input
    cout << "==============================\n";
    cout << "     Grab Fare Estimator\n";
    cout << "==============================\n";
    cout << "[1] GrabCar\n";
    cout << "[2] GrabBike\n";
    cout << "[3] GrabFood\n";
    cout << "Enter your choice: ";
    cin >> service;

    cout << "Enter distance (km): ";
    cin >> distance;

    // Calculation for fees
    switch(service) {
        case 1: fare = 3.0 + (1.5 * distance); break; // GrabCar
        case 2: fare = 2.0 + (1.0 * distance); break; // GrabBike
        case 3: fare = 4.0 + (1.2 * distance); break; // GrabFood
        default:
            cout << "Invalid service type!" << endl;
            return 0;
    }

    // Raise price if in peak hour
    if (isPeakHour(hour)) {
        fare *= 1.5;
    }


        cout << "Hour: " << hour << ":00" << endl;
    cout << "Total Fare: RM " << fare << endl;
    return 0;
}

