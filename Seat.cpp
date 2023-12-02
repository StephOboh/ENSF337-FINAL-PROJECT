//  Seat.cpp
#include "Seat.hpp"

Seat::Seat() : row(0), seat('\0'), reserved(false) {}

Seat::Seat(int row, char seat) : row(row), seat(seat), reserved(false) {}

void Seat::reserve() {
    reserved = true;
}

void Seat::release() {
    reserved = false;
}

bool Seat::isReserved() const {
    return reserved;
}

int Seat::get_row() const {
    return row;
}

char Seat::get_seat() const {
    return seat;
}
