#pragma once

#include <iostream>
#include "../constants/ParkingSpotStatus.h"
#include "../constants/ParkingSpotType.h"
#include "./Vehicle.h"
using namespace std;

// abstract class
class ParkingSpot {
    int id;
    ParkingSpotStatus status;
    const ParkingSpotType type;
    IVehicle *vehicle;
public:
    ParkingSpot(ParkingSpotType _type, int _id): type(_type), id(_id) { status = ParkingSpotStatus::Available; vehicle = NULL; }
    
    void setVehicle(IVehicle *veh) { vehicle = veh; }
    IVehicle* getVehicle() { return vehicle; }
    
    void setStatus(ParkingSpotStatus _status) { status = _status; }
    ParkingSpotStatus getStatus() { return status; }

    virtual ~ParkingSpot() { }
    virtual bool parkVehicle(IVehicle *vehicle) = 0;
    virtual IVehicle* unParkVehicle(IVehicle *vehicle) = 0;
};


/**
 * Car Spot
 */
class CarParkingSpot: public ParkingSpot {
public:
    CarParkingSpot(int id): ParkingSpot(ParkingSpotType::Medium, id) { }

    virtual bool parkVehicle(IVehicle *car) {
        if (this->getVehicle() == NULL) {
            this->setStatus(ParkingSpotStatus::Unavailable);
            this->setVehicle(car);

            return true;
        }

        return false;
    }

    virtual IVehicle* unParkVehicle(IVehicle *car) {
        if (this->getVehicle() == NULL) {
            return NULL;
        }

        IVehicle *vehicle = this->getVehicle();
        this->setVehicle(NULL);
        this->setStatus(ParkingSpotStatus::Available);

        return vehicle;
    }
};