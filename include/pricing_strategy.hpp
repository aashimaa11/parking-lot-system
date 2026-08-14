#ifndef PRICING_STRATEGY_HPP
#define PRICING_STRATEGY_HPP

#include <chrono>

class PricingStrategy {
public:
    virtual double calculatePrice(
        const std::chrono::system_clock::time_point& entryTime,
        const std::chrono::system_clock::time_point& exitTime
    ) = 0;
    virtual ~PricingStrategy() = default;
};

class HourlyPricing : public PricingStrategy {
private:
    double ratePerHour;
public:
    HourlyPricing(double rate = 10.0);
    double calculatePrice(
        const std::chrono::system_clock::time_point& entryTime,
        const std::chrono::system_clock::time_point& exitTime
    ) override;
};

class TieredPricing : public PricingStrategy {
private:
    double firstHourRate;
    double subsequentHourRate;
public:
    TieredPricing(double first = 20.0, double subsequent = 10.0);
    double calculatePrice(
        const std::chrono::system_clock::time_point& entryTime,
        const std::chrono::system_clock::time_point& exitTime
    ) override;
};

#endif