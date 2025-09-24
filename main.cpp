#include <iostream>
using namespace std;

int main() {
    int service;
    cout << "Choose your service:\n";
    cout << "1. GrabCar\n";
    cout << "2. GrabBike\n";
    cout << "3. GrabFood\n";
    cout << "Enter choice: ";
    cin >> service;

    cout << "You chose service: " << service << endl;
    return 0;
}
