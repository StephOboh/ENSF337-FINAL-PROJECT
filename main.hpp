#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Flight.hpp"

void displayMenu();
void displayHeader();
void trim_trailing_spaces(string &str);
Flight populate_flight_from_file(const string &filename);

#endif
