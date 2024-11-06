#pragma once

#include <iostream>
#include <cstdlib>
#include "../constants/ParkingTicketStatus.h"
#include "../service/ParkingFareStrategy.h"
using namespace std;


class ParkingTicket {
    ParkingTicketStatus status;
    string entryTime;
    string exitTime;
    int ticketId;

    IParkingFareStrategy *rate;
public:
    ParkingTicket(string time, IParkingFareStrategy *strategy) {
        ticketId = rand() % INT_MAX;
        status = ParkingTicketStatus::Active;
        entryTime = time;
        rate = strategy;
    }

    /*
        1. Create a ticket object
        2. creation should include the status, issuetime and id
        3. at the time of exit, checkout should present an invoice with required amount
        4. once paid, ticket status is updated to closed
    */
    double checkout(string checkoutTime, VehicleType type) {
        exitTime = checkoutTime;
        return rate->calculateFare(entryTime, exitTime, type);
    }

    void setStatus(ParkingTicketStatus _status) {status = _status; }
    ParkingTicketStatus getStatus() { return status; }

    void setExitTime(string time) {exitTime = time; }
    string getExitTime() {return exitTime; }
};