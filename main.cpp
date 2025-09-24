#include <iostream>
using namespace std;

bool isPeakHour(int hour) {
    return ((hour >= 7 && hour <= 9) || 
            (hour >= 12 && hour <= 14) || 
            (hour >= 17 && hour <= 19));
}

int main() {
    int service, hour;
    double distance, fare = 0.0;

    cout << "Enter current hour (0-23): ";
    cin >> hour;

    cout << "Choose your service:\n";
    cout << "1. GrabCar\n";
    cout << "2. GrabBike\n";
    cout << "3. GrabFood\n";
    cout << "Enter choice: ";
    cin >> service;

    cout << "Enter distance (km): ";
    cin >> distance;

    switch(service) {
        case 1: fare = 3.0 + (1.5 * distance); break;
        case 2: fare = 2.0 + (1.0 * distance); break;
        case 3: fare = 4.0 + (1.2 * distance); break;
        default: cout << "Invalid service type!" << endl; return 0;
    }

    if (isPeakHour(hour)) {
        fare *= 1.5;
    }

    cout << "Hour: " << hour << ":00" << endl;
    cout << "Total Fare: RM " << fare << endl;
    return 0;
}
