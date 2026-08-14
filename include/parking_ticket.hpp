#ifndef PARKING_TICKET_HPP
#define PARKING_TICKET_HPP

#include <chrono>
#include <iostream>
#include <iomanip>
#include "vehicle.hpp"
#include "pricing_strategy.hpp"

class ParkingTicket {
private:
    int ticketId;
    Vehicle* vehicle;
    int floorNumber;
    int spotNumber;
    std::chrono::system_clock::time_point entryTime;
    std::chrono::system_clock::time_point exitTime;
    TicketStatus status;
    double amountDue;

public:
    ParkingTicket(int id, Vehicle* v, int floor, int spot,
                  std::chrono::system_clock::time_point entry);
    
    void closeTicket(std::chrono::system_clock::time_point exit,
                     PricingStrategy* strategy);
    
    int getTicketId() const;
    Vehicle* getVehicle() const;
    int getSpotNumber() const;
    TicketStatus getStatus() const;
    double getAmountDue() const;
    void displayTicket() const;
};

#endif