//  Node.hpp
#include <stdio.h>
#include "Passenger.hpp"

#ifndef Node_hpp
#define Node_hpp



class Node {
public:
    Node(Passenger passenger);
    Passenger get_passenger() const;
    Node* get_next() const;
    void set_next(Node* nextNode);

private:
    Passenger passenger;
    Node* next;
};

#endif /* Node_hpp */
