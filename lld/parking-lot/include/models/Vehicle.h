#pragma once

#include <iostream>
#include "../constants/VehicleType.h"
#include "ParkingTicket.h"
using namespace std;


class IVehicle {
    VehicleType type;
    string registrationNumber;
    ParkingTicket *ticket;
public:
    IVehicle(VehicleType _type, string id): registrationNumber(id), type(_type) { }
    virtual void setParkingTicket(ParkingTicket *_ticket) {
        ticket = _ticket;
    }
    virtual ~IVehicle() { }
};


/**
 * Car
 */
class Car: public IVehicle {
public:
    Car(string id): IVehicle(VehicleType::Car, id) { }
};


/**
 * Bike
 */
class Bike: public IVehicle {
public:
    Bike(string id): IVehicle(VehicleType::Bike, id) { }
};