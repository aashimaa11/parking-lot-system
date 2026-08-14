#ifndef PARKING_SPOT_HPP
#define PARKING_SPOT_HPP

#include "enums.hpp"
#include "vehicle.hpp"

class ParkingSpot {
private:
    int spotNumber;
    SpotType type;
    bool isOccupied;
    Vehicle* parkedVehicle;

public:
    ParkingSpot(int num, SpotType t);
    
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* unparkVehicle();
    bool isAvailable() const;
    int getSpotNumber() const;
    bool canFitVehicle(Vehicle* vehicle) const;
};

#endif