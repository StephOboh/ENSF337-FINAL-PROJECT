//  Passenger.cpp
#include "Passenger.hpp"
#include <iostream>
using namespace std;




#include "Passenger.hpp"
#include <iostream>

Passenger::Passenger() : id(0), seat(nullptr) {}

Passenger::Passenger(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, int id, Seat* seat)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), id(id), seat(seat) {}

void Passenger::displayInfo() const {
    std::cout << firstName << " " << lastName << " " << phoneNumber << " " << seat->get_row() << seat->get_seat() << " " << id << std::endl;
}

int Passenger::get_ID() const {
    return id;
}

Seat* Passenger::get_seat() const {
    return seat;
}

std::string Passenger::get_firstName() const {
    return firstName;
}

std::string Passenger::get_lastName() const {
    return lastName;
}

std::string Passenger::get_phoneNumber() const {
    return phoneNumber;
}
