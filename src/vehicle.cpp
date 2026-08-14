#include "vehicle.hpp"

Vehicle::Vehicle(std::string plate, VehicleType t, std::string owner)
    : licensePlate(plate), type(t), ownerName(owner) {}

std::string Vehicle::getLicensePlate() const { 
    return licensePlate; 
}

VehicleType Vehicle::getType() const { 
    return type; 
}

SpotType Vehicle::getRequiredSpotType() const {
    switch(type) {
        case VehicleType::CAR: return SpotType::COMPACT;
        case VehicleType::BIKE: return SpotType::COMPACT;
        case VehicleType::TRUCK: return SpotType::LARGE;
        case VehicleType::ELECTRIC: return SpotType::ELECTRIC;
        default: return SpotType::COMPACT;
    }
}