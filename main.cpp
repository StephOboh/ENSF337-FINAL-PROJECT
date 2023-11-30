#include <iostream>
#include <string>
#include <fstream>
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
    Flight flight("WJ1045",20,5);
    populate_flight_from_file("flight_info.txt");
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
                cout << "Phone Number: ";
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
                if (answer == 'Y' || answer == 'y') {
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
    

void populate_flight_from_file(const string &filename){
    ifstream file(filename);
    if(file.fail()){
        cout << "Unable to open file" << endl;
        return;
    }

    int current_line = 1;
    string line;
    while(!file.eof()){
        current_line++;
        getline(file, line);
        cout << line << endl;
    }
    
    file.close();
    
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






