#include <iostream>
using namespace std;

int main() {
    int service;
    double distance;

    cout << "Choose your service:\n";
    cout << "1. GrabCar\n";
    cout << "2. GrabBike\n";
    cout << "3. GrabFood\n";
    cout << "Enter choice: ";
    cin >> service;

    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Service: " << service << ", Distance: " << distance << " km" << endl;
    return 0;
}
