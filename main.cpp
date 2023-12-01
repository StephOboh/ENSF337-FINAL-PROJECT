#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Flight.hpp"
#include "Flight.cpp"
#include "Node.hpp"
#include "Node.cpp"
#include "Seat.hpp"
#include "Seat.cpp"
#include "Passenger.hpp"
#include "Passenger.cpp"
#include "main.hpp"
using namespace std;

int main() {
    int choice;
    Flight flight = populate_flight_from_file("flight_info.txt");
    
    displayHeader();
    do {
        // Display menu
       displayMenu();
       cin >> choice;
        

        // Process user choice
        switch (choice) {
            case 1:
                flight.displaySeatMap();
                break;
            case 2:
                flight.displayPassengerInfo();
                break;
            case 3: {
                string firstName, lastName, phoneNumber;
                int id, row;
                char seat;
                cout << "Please enter the passenger details:\n";
                cout << "First Name: ";
                cin >> firstName;
                cout << "Last Name: ";
                cin >> lastName;
                cout << "Phone Number (XXX-XXX-XXXX): ";
                cin >> phoneNumber;
                cout << "ID: ";
                cin >> id;
                cout << "Desired Row Number: ";
                cin >> row;
                cout << "Desired Seat Letter: ";
                cin >> seat;
                flight.addPassenger(firstName, lastName, phoneNumber, id, row, seat);
                break;
            }
            case 4: {
                flight.displayPassengerInfo();
                int id;
                cout << "Please enter the ID of the passenger to be removed: ";
                cin >> id;
                flight.removePassenger(id);
                break;
            }
            case 5: {
                string filename;
                char answer;
                cout << "Do you want to save the data into 'flight_info.txt'? Please answer <Y or N>: ";
                cin >> answer;
                if (tolower(answer) == 'y') {
                    cout << "Enter the filename: ";
                    cin >> filename;
                    flight.saveDataToFile(filename);
                }
                break;
            }
            case 6:
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}
    

Flight populate_flight_from_file(const string &filename){

    ifstream file(filename);
    if(file.fail()){
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string plane_id, line;
    int rows, seats;
    getline(file, line);
    stringstream plane_info(line);
    plane_info >> plane_id >> rows >> seats;
    Flight flight(plane_id, rows, seats);

    char s[21];
    string first_name, last_name, phone_number;
    int id, row;
    char seatletter;
    do{
        file.get(s, 21, '\0');
        if(file.eof()){
            break;
        }
        first_name = s;
        trim_trailing_spaces(first_name);

        file.get(s, 21, '\0');
        if(file.eof()){
            break;
        }
        last_name = s;
        trim_trailing_spaces(last_name);

        file.get(s, 21, '\0');
        if(file.eof()){
            break;
        }
        phone_number = s;
        trim_trailing_spaces(phone_number);

        file>>row>> seatletter>>id;
        flight.addPassenger(first_name, last_name, phone_number, id, row, seatletter);




    }while(!file.eof());
    

    
    file.close();
    return flight;

    
}
void displayHeader(){
    cout << "Version: 1.0\n"
        << "Term Project - Flight Management Program in C++\n"
        << "Produced by: Student Name\n"
        << "Year: 2023\n"
        << "<<< Press Return to Continue>>>>\n";

    cin.ignore();
}

void displayMenu(){
    
    cout << "Please select one of the following options:\n"
                << "1. Display Flight Seat Map.\n"
                << "2. Display Passengers Information.\n"
                << "3. Add a New Passenger.\n"
                << "4. Remove an Existing Passenger.\n"
                << "5. Save data.\n"
                << "6. Quit.\n"
                << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
}



void trim_trailing_spaces(string &str) {
    size_t endpos = str.find_last_not_of(" \t");
    if (string::npos != endpos) {
        str = str.substr(0, endpos + 1);
    }
}
