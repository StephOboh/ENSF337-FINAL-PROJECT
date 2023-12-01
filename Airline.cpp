#include <iostream>
#include <string>
#include <vector>
#include "Airline.hpp"
using namespace std;

void Airline::getFlightName() {
    return flightname;
}

void Airline::setFlightName(string name) {
    flightname = name;
}

void Airline::addFlight(Flight flight) {
    flights.push_back(flight);
}

void Airline::getNumberOfFlights() {
    return flights.size();
}

