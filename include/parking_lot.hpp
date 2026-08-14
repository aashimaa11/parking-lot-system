#ifndef PARKING_LOT_HPP
#define PARKING_LOT_HPP

#include <vector>
#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include "parking_floor.hpp"
#include "parking_ticket.hpp"
#include "pricing_strategy.hpp"

class ParkingLot {
private:
    static ParkingLot* instance;
    std::vector<std::unique_ptr<ParkingFloor>> floors;
    std::map<std::string, ParkingTicket*> activeTickets;
    std::map<int, ParkingTicket*> ticketHistory;
    int ticketCounter;
    PricingStrategy* pricingStrategy;
    
    ParkingLot();

public:
    static ParkingLot* getInstance();
    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;
    ~ParkingLot();
    
    void addFloor(int floorNum, int compactSpots, int largeSpots,
                  int handicappedSpots, int electricSpots);
    void setPricingStrategy(PricingStrategy* strategy);
    ParkingTicket* parkVehicle(Vehicle* vehicle);
    bool unparkVehicle(std::string licensePlate);
    void displayStatus() const;
    double getRevenue() const;
};

#endif