#include "pricing_strategy.hpp"
#include <algorithm>

// Hourly Pricing
HourlyPricing::HourlyPricing(double rate) : ratePerHour(rate) {}

double HourlyPricing::calculatePrice(
    const std::chrono::system_clock::time_point& entryTime,
    const std::chrono::system_clock::time_point& exitTime) {
    auto duration = std::chrono::duration_cast<std::chrono::hours>(exitTime - entryTime);
    int hours = std::max(1, (int)duration.count());
    return hours * ratePerHour;
}

// Tiered Pricing
TieredPricing::TieredPricing(double first, double subsequent) 
    : firstHourRate(first), subsequentHourRate(subsequent) {}

double TieredPricing::calculatePrice(
    const std::chrono::system_clock::time_point& entryTime,
    const std::chrono::system_clock::time_point& exitTime) {
    auto duration = std::chrono::duration_cast<std::chrono::hours>(exitTime - entryTime);
    int hours = std::max(1, (int)duration.count());
    if (hours <= 1) return firstHourRate;
    return firstHourRate + (hours - 1) * subsequentHourRate;
}