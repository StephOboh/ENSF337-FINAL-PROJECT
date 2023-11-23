//  Flight.hpp
#include <stdio.h>
#include <string>
#include "Node.hpp"
using namespace std;

#ifndef Flight_hpp
#define Flight_hpp



class Flight {
public:
    Flight(const string& flightNumber, int numRows, int numSeatsPerRow);
    void displaySeatMap() const;
    void displayPassengerInfo() const;
    void addPassenger(const string& firstName, const string& lastName, const string& phoneNumber, int id, int row, char seat);
    void removePassenger(int id);
    void saveDataToFile(const string& filename) const;
    ~Flight(); // Destructor to free the memory used by the linked list

private:
    string flightNumber;
    int numRows;
    int numSeatsPerRow;
    vector<vector<Seat>> seatMap;
    Node* head; // Head of the linked list
    
    //void initializeSeatMap();  potentially needed
};

#endif /* Flight_hpp */
