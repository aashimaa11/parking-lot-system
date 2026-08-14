#include "parking_spot.hpp"

ParkingSpot::ParkingSpot(int num, SpotType t)
    : spotNumber(num), type(t), isOccupied(false), parkedVehicle(nullptr) {}

bool ParkingSpot::parkVehicle(Vehicle* vehicle) {
    if (isOccupied) return false;
    if (!canFitVehicle(vehicle)) return false;
    parkedVehicle = vehicle;
    isOccupied = true;
    return true;
}

Vehicle* ParkingSpot::unparkVehicle() {
    if (!isOccupied) return nullptr;
    Vehicle* vehicle = parkedVehicle;
    parkedVehicle = nullptr;
    isOccupied = false;
    return vehicle;
}

bool ParkingSpot::isAvailable() const { 
    return !isOccupied; 
}

int ParkingSpot::getSpotNumber() const { 
    return spotNumber; 
}

bool ParkingSpot::canFitVehicle(Vehicle* vehicle) const {
    if (!vehicle) return false;
    
    // Truck can only park in LARGE spots
    if (vehicle->getType() == VehicleType::TRUCK) {
        return type == SpotType::LARGE;
    }
    
    // Cars and bikes can park in COMPACT or HANDICAPPED
    if (type == SpotType::COMPACT || type == SpotType::HANDICAPPED) {
        return true;
    }
    
    // ELECTRIC spot can be used by any vehicle
    if (type == SpotType::ELECTRIC) {
        return true;
    }
    
    return false;
}