//  Flight.cpp
#include "Flight.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

Flight::Flight() : flightNumber(""), numRows(0), numSeatsPerRow(0), head(nullptr) {}

Flight::Flight(const string& flightNumber, int numRows, int numSeatsPerRow)
    : flightNumber(flightNumber), numRows(numRows), numSeatsPerRow(numSeatsPerRow), head(nullptr) {
    seatMap.resize(numRows, vector<Seat>(numSeatsPerRow));

    // Initialize seatMap
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numSeatsPerRow; ++j) {
            seatMap[i][j] = Seat(i + 1, static_cast<char>('A' + j));
        }
    }
}

void Flight::displaySeatMap() const {
    cout<<""<<endl;
    cout << "      Aircraft Seat Map" << endl;
    cout << "   ";
    for(char c = 'A'; c < 'A' + numSeatsPerRow; c++) {
        cout << setw(4) <<c;

    }
    cout << endl;

    for (int i = 0; i<numRows; i++){
        cout<< setw(5) << "+";
        for (int j = 0; j<numSeatsPerRow; j++){
            cout << "---+";
        }
        cout << endl;
        if(i < 9){
            cout << i + 1 << " ";

        }
        else{
            cout << i + 1;
        }

        for(int j = 0; j < numSeatsPerRow; j++){
            cout << setw(3) <<"|" << (seatMap[i][j].isReserved() ? "X" : " ");
        }
        cout<< setw(3) << "|" << endl;
    }
    cout << setw(5) << "+";
    for (int j = 0; j < numSeatsPerRow; j++){
        cout << "---+";
    }
    cout << endl;
    
     
}

void Flight::displayPassengerInfo()  {
    // Display passenger information using the linked list
    cout <<left<<setw(20)<<"First Name";
    cout <<left<<setw(20)<<"Last Name";
    cout <<left<<setw(16)<<"Phone Number";
    cout <<left<<setw(12)<<"Row";
    cout <<left<<setw(8)<<"Seat";
    cout <<left<<"ID"<<endl;


    cout << "---------------------------------------------------------------------------------" << endl;

    Node* curr = head;

  
    // Traverse list 
    while (curr != nullptr) {
        Passenger passenger = curr->get_passenger();
        Seat passengerSeat = passenger.get_seat();

        cout << setw(20) << left << passenger.get_firstName()
                << setw(20) << left << passenger.get_lastName()
                << setw(16) << left << passenger.get_phoneNumber()
        << setw(11) << left << passengerSeat.get_row()
        << setw(7) << left << passengerSeat.get_seat()
                << passenger.get_ID() << endl;
        cout << "---------------------------------------------------------------------------------" << endl;

        curr = curr->get_next();
    }
    
}

void Flight::addPassenger(const string& firstName, const string& lastName, const string& phoneNumber, int id, int row, char seatChar) {
    // Add a new passenger to the linked list
    // Check if the seat is within valid range
        if (row < 1 || row > numRows || seatChar < 'A' || seatChar >= 'A' + numSeatsPerRow) {
            cout << "Invalid seat selection. Please try again." << endl;
            return;
        }

        // Check if the seat is already reserved
        if (seatMap[row - 1][seatChar - 'A'].isReserved()) {
            cout << "Seat " << seatChar << " in row " << row << " is already reserved. Please choose another seat." << endl;
            return;
        }

        // Add a new passenger to the linked list
        Seat seat(row, seatChar);
        Passenger newPassenger(firstName, lastName, phoneNumber, id, seat);
    
        Node* newNode = new Node(newPassenger);
        newNode->set_next(head);
        head = newNode;

        // Reserve the corresponding seat in the seatMap
        seatMap[row - 1][seatChar - 'A'].reserve();

    
    /*Seat seat(row, seatChar);
    Passenger newPassenger(firstName, lastName, phoneNumber, id, seat);

    Node* newNode = new Node(newPassenger);
    newNode->set_next(head);
    head = newNode;

    // Reserve the corresponding seat in the seatMap
    seatMap[row - 1][seatChar - 'A'].reserve();
    */
}

void Flight::removePassenger(int id) {
    // Remove the passenger with the given id from the linked list
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->get_passenger().get_ID() != id) {
        previous = current;
        current = current->get_next();
    }

    if (current == nullptr) {
        cout << "Passenger with ID " << id << " not found.\n";
        return;
    }

    if (previous == nullptr) {
        // Removing the head of the linked list
        head = current->get_next();
    } else {
        previous->set_next(current->get_next());
    }

    // Release the corresponding seat in the seatMap
    Seat passengerSeat = current->get_passenger().get_seat();
    seatMap[passengerSeat.get_row() - 1][passengerSeat.get_seat() - 'A'].release();

    delete current;
}

void Flight::saveDataToFile(const string& filename) const {
    // Save passenger information to the file
    ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        // Write flight information (flightNumber, numRows, numSeatsPerRow)
        outFile << flightNumber << " " << numRows << " " << numSeatsPerRow << endl;

        // Write passenger information
        Node* current = head;
        while (current != nullptr) {
            Passenger passenger = current->get_passenger();
            Seat passengerSeat = passenger.get_seat();

            outFile << passenger.get_firstName() << " "
                    << passenger.get_lastName() << " "
                    << passenger.get_phoneNumber() << " "
                    << passenger.get_ID() << " "
            << passengerSeat.get_row() << passengerSeat.get_seat() << endl;

            current = current->get_next();
        }

        outFile.close();

        cout << "Flight information saved to " << filename << endl;
    
    /*ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        outFile << current->get_passenger().get_ID() << " "
                << current->get_passenger().get_firstName() << " "
                << current->get_passenger().get_lastName() << " "
                << current->get_passenger().get_phoneNumber() << " "
                << current->get_passenger().get_seat().get_row() << current->get_passenger().get_seat().get_seat() << endl;
        current = current->get_next();
    }

    outFile.close();
     */
}

Flight::~Flight() {
    // Destructor to free the memory used by the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->get_next();
        delete current;
        current = next;
    }
}
