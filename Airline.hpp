#ifndef AIRLINE.HPP
#define AIRLINE.HPP
#include <iostream>
#include <string>
#include <vector>
#include "Flight.hpp"
using namespace std;

class Airline {
    public:
        void getFlightName() const;
        void setFlightName(string name);
        void addFlight(Flight flight);
        void getNumberOfFlights();

    private:
        string flightname;
        vector<Flight> flights;
        int numberOfFlights;

};

#endif
