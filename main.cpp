#include <iostream>
#include <iomanip>
#include <ctime>   
using namespace std;

bool isPeakHour(int hhmm) {
    return ((hhmm >= 700 && hhmm <= 900) ||   
            (hhmm >= 1200 && hhmm <= 1400) || 
            (hhmm >= 1700 && hhmm <= 1900));  
}

int main() {
    int service;
    double distance, fare = 0.0;

    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;   // 0-23
    int minute = ltm->tm_min;  // 0-59
    int hhmm = hour * 100 + minute; // e.g. 9:01 -> 901

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
    if (isPeakHour(hhmm)) {
        fare *= 1.5;
    }

    // output
    cout << fixed << setprecision(2);
    cout << "\n==============================\n";
    cout << "         Fare Summary\n";
    cout << "==============================\n";
    if (service == 1) cout << "Service: GrabCar" << endl;
    else if (service == 2) cout << "Service: GrabBike" << endl;
    else cout << "Service: GrabFood" << endl;

    cout << "Distance: " << distance << " km" << endl;
    cout << "Current Time: " 
         << setw(2) << setfill('0') << hour << ":" 
         << setw(2) << setfill('0') << minute << endl;

    if (isPeakHour(hhmm)) {
        cout << "Peak Hour Surcharge Applied!" << endl;
    } else {
        cout << "Normal Rate" << endl;
    }

    cout << "Total Fare: RM " << fare << endl;
    cout << "==============================\n";

    return 0;
}
