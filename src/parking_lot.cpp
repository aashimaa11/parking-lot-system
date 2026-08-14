#include "parking_lot.hpp"

ParkingLot* ParkingLot::instance = nullptr;

ParkingLot::ParkingLot() : ticketCounter(1), pricingStrategy(nullptr) {
    pricingStrategy = new HourlyPricing(10.0);
}

ParkingLot* ParkingLot::getInstance() {
    if (!instance) {
        instance = new ParkingLot();
    }
    return instance;
}

ParkingLot::~ParkingLot() {
    if (pricingStrategy) delete pricingStrategy;
    for (auto& pair : ticketHistory) {
        delete pair.second;
    }
}

void ParkingLot::addFloor(int floorNum, int compactSpots, int largeSpots,
                          int handicappedSpots, int electricSpots) {
    floors.push_back(std::make_unique<ParkingFloor>(floorNum, compactSpots,
                                                    largeSpots, handicappedSpots,
                                                    electricSpots));
}

void ParkingLot::setPricingStrategy(PricingStrategy* strategy) {
    if (pricingStrategy) delete pricingStrategy;
    pricingStrategy = strategy;
}

ParkingTicket* ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (!vehicle) return nullptr;
    
    if (activeTickets.find(vehicle->getLicensePlate()) != activeTickets.end()) {
        std::cout << "Vehicle already parked!" << std::endl;
        return nullptr;
    }
    
    for (auto& floor : floors) {
        auto result = floor->parkVehicle(vehicle);
        if (result.first) {
            ParkingSpot* spot = result.second;
            ParkingTicket* ticket = new ParkingTicket(
                ticketCounter++,
                vehicle,
                floor->getFloorNumber(),
                spot->getSpotNumber(),
                std::chrono::system_clock::now()
            );
            
            activeTickets[vehicle->getLicensePlate()] = ticket;
            ticketHistory[ticket->getTicketId()] = ticket;
            
            std::cout << "Vehicle " << vehicle->getLicensePlate() 
                      << " parked at Floor " << floor->getFloorNumber() 
                      << ", Spot " << spot->getSpotNumber()
                      << " | Ticket #" << ticket->getTicketId() << std::endl;
            
            return ticket;
        }
    }
    
    std::cout << "No available spot for vehicle " << vehicle->getLicensePlate() << std::endl;
    return nullptr;
}

bool ParkingLot::unparkVehicle(std::string licensePlate) {
    auto it = activeTickets.find(licensePlate);
    if (it == activeTickets.end()) {
        std::cout << "Vehicle not found in parking lot!" << std::endl;
        return false;
    }
    
    ParkingTicket* ticket = it->second;
    
    for (auto& floor : floors) {
        Vehicle* vehicle = floor->unparkVehicle(ticket->getSpotNumber());
        if (vehicle) {
            ticket->closeTicket(std::chrono::system_clock::now(), pricingStrategy);
            activeTickets.erase(it);
            
            std::cout << "Vehicle " << licensePlate << " unparked. Total due: Rs " 
                      << std::fixed << std::setprecision(2) << ticket->getAmountDue() << std::endl;
            return true;
        }
    }
    
    std::cout << "Error: Vehicle not found in specified spot!" << std::endl;
    return false;
}

void ParkingLot::displayStatus() const {
    std::cout << "\n=== PARKING LOT STATUS ===" << std::endl;
    for (const auto& floor : floors) {
        floor->displayFloorStatus();
    }
    std::cout << "Active Vehicles: " << activeTickets.size() << std::endl;
    std::cout << "Total Revenue: Rs " << std::fixed << std::setprecision(2) << getRevenue() << std::endl;
    std::cout << "===========================\n" << std::endl;
}

double ParkingLot::getRevenue() const {
    double total = 0;
    for (const auto& pair : ticketHistory) {
        if (pair.second->getStatus() == TicketStatus::PAID) {
            total += pair.second->getAmountDue();
        }
    }
    return total;
}