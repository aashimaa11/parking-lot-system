#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include "enums.hpp"

class Vehicle {
private:
    std::string licensePlate;
    VehicleType type;
    std::string ownerName;

public:
    Vehicle(std::string plate, VehicleType t, std::string owner = "");
    
    std::string getLicensePlate() const;
    VehicleType getType() const;
    SpotType getRequiredSpotType() const;
};

#endif