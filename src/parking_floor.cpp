#include "parking_floor.hpp"

ParkingFloor::ParkingFloor(int floorNum, int compactSpots, int largeSpots,
                           int handicappedSpots, int electricSpots)
    : floorNumber(floorNum) {
    int spotCounter = 1;
    
    for (int i = 0; i < compactSpots; i++) {
        spots.push_back(std::make_unique<ParkingSpot>(spotCounter++, SpotType::COMPACT));
    }
    for (int i = 0; i < largeSpots; i++) {
        spots.push_back(std::make_unique<ParkingSpot>(spotCounter++, SpotType::LARGE));
    }
    for (int i = 0; i < handicappedSpots; i++) {
        spots.push_back(std::make_unique<ParkingSpot>(spotCounter++, SpotType::HANDICAPPED));
    }
    for (int i = 0; i < electricSpots; i++) {
        spots.push_back(std::make_unique<ParkingSpot>(spotCounter++, SpotType::ELECTRIC));
    }
}

ParkingSpot* ParkingFloor::findAvailableSpot(Vehicle* vehicle) {
    for (auto& spot : spots) {
        if (!spot->isAvailable()) continue;
        if (spot->canFitVehicle(vehicle)) {
            return spot.get();
        }
    }
    return nullptr;
}

std::pair<bool, ParkingSpot*> ParkingFloor::parkVehicle(Vehicle* vehicle) {
    ParkingSpot* spot = findAvailableSpot(vehicle);
    if (!spot) return {false, nullptr};
    if (spot->parkVehicle(vehicle)) return {true, spot};
    return {false, nullptr};
}

Vehicle* ParkingFloor::unparkVehicle(int spotNumber) {
    for (auto& spot : spots) {
        if (spot->getSpotNumber() == spotNumber) {
            if (!spot->isAvailable()) {
                return spot->unparkVehicle();
            }
            break;
        }
    }
    return nullptr;
}

int ParkingFloor::getTotalAvailableSpots() const {
    int total = 0;
    for (auto& spot : spots) {
        if (spot->isAvailable()) total++;
    }
    return total;
}

// THIS METHOD WAS MISSING - ADD IT!
int ParkingFloor::getFloorNumber() const {
    return floorNumber;
}

void ParkingFloor::displayFloorStatus() const {
    std::cout << "  Floor " << floorNumber 
              << " (Available: " << getTotalAvailableSpots() << "): ";
    for (auto& spot : spots) {
        std::cout << (spot->isAvailable() ? "[FREE]" : "[OCC]");
    }
    std::cout << std::endl;
}