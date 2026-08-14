#ifndef PARKING_FLOOR_HPP
#define PARKING_FLOOR_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "parking_spot.hpp"

class ParkingFloor {
private:
    int floorNumber;
    std::vector<std::unique_ptr<ParkingSpot>> spots;

public:
    ParkingFloor(int floorNum, int compactSpots, int largeSpots,
                 int handicappedSpots, int electricSpots);
    
    ParkingSpot* findAvailableSpot(Vehicle* vehicle);
    std::pair<bool, ParkingSpot*> parkVehicle(Vehicle* vehicle);
    Vehicle* unparkVehicle(int spotNumber);
    int getTotalAvailableSpots() const;
    int getFloorNumber() const;  // ← THIS LINE WAS MISSING!
    void displayFloorStatus() const;
};

#endif