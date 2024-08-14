#pragma once
#ifndef CREATOR_H_
#define CREATOR_H_

#include <iostream>
#include "../product/product.h"
using namespace std;


/*
Creator Interface - TransportFactory
- To be followed by all factories
- Each product would have its own factory to create their object
*/
class TransportFactory {
public:
    virtual ~TransportFactory() {}
    virtual Transport* create() = 0;
};

// TruckFactory
class TruckFactory: public TransportFactory {
public:
    virtual Transport* create() {
        Transport *obj = new TruckTransport();
        return obj;
    }
};


// ShipFactory
class ShipFactory: public TransportFactory {
public:
    virtual Transport* create() {
        Transport *obj = new ShipTransport();
        return obj;
    }
};

#endif
