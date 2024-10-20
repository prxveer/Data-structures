#include <iostream>
using namespace std;

class Flight {
private:
    int flight_number;
    string destination;
    float distance;
    float fuel;

    void calculate_fuel() {
        if (distance <= 1000) {
            fuel = 500;
        } else if (distance <= 2000) {
            fuel = 1100;
        } else {
            fuel = 2200;
        }
    }

public:
    Flight(float initial_fuel = 13.2) : fuel(initial_fuel) {}

    void information_entry() {
        cout << "Enter Flight Number: ";
        cin >> flight_number;
        cin.ignore();

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Distance (in kilometers): ";
        cin >> distance;

        calculate_fuel();
    }

    void display_info() {
        cout << "\nFlight Number: " << flight_number << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Fuel Required: " << fuel << " liters" << endl;
    }

    void set_fuel(float additional_fuel) {
        fuel = additional_fuel;
    }
};

int main() {
    Flight flight;

    flight.information_entry();
    flight.display_info();

    return 0;
}
