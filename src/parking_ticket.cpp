#include "parking_ticket.hpp"

ParkingTicket::ParkingTicket(int id, Vehicle* v, int floor, int spot,
                             std::chrono::system_clock::time_point entry)
    : ticketId(id), vehicle(v), floorNumber(floor), spotNumber(spot),
      entryTime(entry), status(TicketStatus::ACTIVE), amountDue(0.0) {}

void ParkingTicket::closeTicket(std::chrono::system_clock::time_point exit,
                                PricingStrategy* strategy) {
    exitTime = exit;
    status = TicketStatus::PAID;
    amountDue = strategy->calculatePrice(entryTime, exitTime);
}

int ParkingTicket::getTicketId() const { 
    return ticketId; 
}

Vehicle* ParkingTicket::getVehicle() const { 
    return vehicle; 
}

int ParkingTicket::getSpotNumber() const { 
    return spotNumber; 
}

TicketStatus ParkingTicket::getStatus() const { 
    return status; 
}

double ParkingTicket::getAmountDue() const { 
    return amountDue; 
}

void ParkingTicket::displayTicket() const {
    auto entryTime_t = std::chrono::system_clock::to_time_t(entryTime);
    std::cout << "\n=== PARKING TICKET ===" << std::endl;
    std::cout << "Ticket ID: " << ticketId << std::endl;
    std::cout << "Vehicle: " << vehicle->getLicensePlate() << std::endl;
    std::cout << "Floor: " << floorNumber << std::endl;
    std::cout << "Spot: " << spotNumber << std::endl;
    std::cout << "Entry Time: " 
              << std::put_time(std::localtime(&entryTime_t), "%Y-%m-%d %H:%M:%S") << std::endl;
    
    if (status == TicketStatus::PAID) {
        auto exitTime_t = std::chrono::system_clock::to_time_t(exitTime);
        std::cout << "Amount Due: Rs " << std::fixed << std::setprecision(2) << amountDue << std::endl;
    }
    std::cout << "=====================\n" << std::endl;
}