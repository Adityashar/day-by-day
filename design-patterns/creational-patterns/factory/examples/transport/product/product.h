#pragma once
#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;


/*
Product Interface - Transport
*/

class Transport {
public:
    virtual ~Transport() {}
    virtual void deliver() = 0;  
};


// TruckTransport
class TruckTransport: public Transport {
    string name;
public:
    TruckTransport() {
        name = "Truck";
    }
    virtual void deliver() {
        printf("Transport: Made delivery via '%s'\n", name.c_str());
    }
};


// ShipTransport
class ShipTransport: public Transport {
    string name;
public:
    ShipTransport() {
        name = "Ship";
    }
    virtual void deliver() {
        printf("Transport: Made delivery via '%s'\n", name.c_str());
    }
};


#endif