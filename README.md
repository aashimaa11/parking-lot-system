# 🅿️ Parking Lot Management System

A C++ implementation of a multi-level parking lot management system using OOP principles and Design Patterns.

## 📌 Features

- **4 Vehicle Types**: Car, Bike, Truck, Electric
- **4 Spot Types**: Compact, Large, Handicapped, Electric
- **3 Pricing Strategies**: Hourly, Flat Rate, Tiered
- **Design Patterns**: Singleton, Strategy
- **Real-time Status**: Display floor-wise availability
- **Revenue Tracking**: Automatic payment calculation

## 🛠️ Tech Stack

- C++17
- STL (Standard Template Library)
- OOP Principles
- Design Patterns

## 📖 What This Project Does

This project simulates a **real-world parking lot system** where:

-  **Vehicles** of different types (Car, Bike, Truck, Electric) can be parked
-  **Spots** are intelligently allocated based on vehicle size and type
-  **Pricing** is calculated dynamically using different strategies (Hourly, Flat Rate, Tiered)
-  **Tickets** are generated for each vehicle with entry/exit timestamps
-  **Revenue** is tracked automatically across all transactions
-  **Status** can be viewed in real-time showing which spots are free/occupied

The system is designed with **clean architecture**, making it easy to add new vehicle types, spot types, or pricing strategies without modifying existing code.

**Screenshots**
<img width="1790" height="961" alt="parking-lot screenshot1" src="https://github.com/user-attachments/assets/ea46ca87-4656-4964-a105-a45a1ddf0674" />

<img width="1778" height="962" alt="parking-lot screenshot2" src="https://github.com/user-attachments/assets/f76e6b74-2955-46ba-981f-00aab4292e1c" />

## 🚀 How to Run

### Method: Using Terminal
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o build/parking_lot.exe
./build/parking_lot.exe
