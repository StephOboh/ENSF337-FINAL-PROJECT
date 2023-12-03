// Airline.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Airline.hpp"
using namespace std;

string Airline::getFlightName() const {
    return flightname;
}

void Airline::setFlightName(string name) {
    if (!name.empty()) {
        flightname = name;
    } else {
        cout << "Error: Invalid flight name. Please enter a non-empty name." << endl;
    }
}

void Airline::addFlight(Flight flight) {
    flights.push_back(flight);
}

unsigned long Airline::getNumberOfFlights() {
    return flights.size();
}

