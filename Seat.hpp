//  Seat.hpp
#include <stdio.h>

#ifndef Seat_hpp
#define Seat_hpp

class Seat {
public:
    Seat();
    Seat(int row, char seat);
    void reserve();
    void release();
    bool isReserved() const;
    int get_row() const;
    char get_seat() const;

private:
    int row;
    char seat;
    bool reserved;
};


#endif /* Seat_hpp */

