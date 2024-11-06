#pragma once

#include <iostream>
#include "../constants/VehicleType.h"
using namespace std;


class IParkingFareStrategy {
    double amount;
public:
    IParkingFareStrategy() { amount = 0; }
    void setAmount(double amt) { amount = amt; }
    double getAmount() { return amount; }

    virtual ~IParkingFareStrategy() { }
    virtual double calculateFare(string entryTime, string exitTime, VehicleType type) = 0;
};

/**
 * EqualRates Strategy
 */
class EqualRatesStrategy: public IParkingFareStrategy {
    double hourlyRate;
public:
    EqualRatesStrategy(double amt): hourlyRate(amt) { }

    virtual double calculateFare(string entryTime, string exitTime, VehicleType type) {
        int hours = stoi(exitTime) - stoi(entryTime);
        this->setAmount(hours * this->hourlyRate);
        return this->getAmount();
    }
};

/**
 * VehicleRates Strategy
 */