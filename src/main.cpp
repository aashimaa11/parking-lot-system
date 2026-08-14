#include <iostream>
#include "parking_lot.hpp"

void runParkingLotDemo() {
    ParkingLot* parkingLot = ParkingLot::getInstance();
    
    // Add floors with spots
    parkingLot->addFloor(1, 3, 1, 1, 1);
    parkingLot->addFloor(2, 4, 2, 0, 1);
    
    // Set pricing strategy
    parkingLot->setPricingStrategy(new TieredPricing(20.0, 10.0));
    
    // Display initial status
    parkingLot->displayStatus();
    
    // Create vehicles
    Vehicle car1("KA-01-1234", VehicleType::CAR, "Alice");
    Vehicle car2("KA-02-5678", VehicleType::CAR, "Bob");
    Vehicle bike1("KA-03-9012", VehicleType::BIKE, "Charlie");
    Vehicle truck1("KA-04-3456", VehicleType::TRUCK, "David");
    Vehicle electric1("KA-05-7890", VehicleType::ELECTRIC, "Eve");
    
    // Park vehicles
    std::cout << "\n=== PARKING VEHICLES ===" << std::endl;
    ParkingTicket* t1 = parkingLot->parkVehicle(&car1);
    ParkingTicket* t2 = parkingLot->parkVehicle(&car2);
    ParkingTicket* t3 = parkingLot->parkVehicle(&bike1);
    ParkingTicket* t4 = parkingLot->parkVehicle(&truck1);
    ParkingTicket* t5 = parkingLot->parkVehicle(&electric1);
    std::cout << std::endl;
    
    // Display status after parking
    parkingLot->displayStatus();
    
    // Display tickets for first two vehicles
    if (t1) t1->displayTicket();
    if (t2) t2->displayTicket();
    
    // Unpark vehicles
    std::cout << "\n=== UNPARKING VEHICLES ===" << std::endl;
    parkingLot->unparkVehicle("KA-01-1234");
    parkingLot->unparkVehicle("KA-03-9012");
    std::cout << std::endl;
    
    // Display final status
    parkingLot->displayStatus();
}

int main() {
    runParkingLotDemo();
    return 0;
}