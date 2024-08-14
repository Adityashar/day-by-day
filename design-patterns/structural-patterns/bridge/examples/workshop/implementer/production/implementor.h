#pragma once
#ifndef P_IMPLEMENTOR_H_
#define P_IMPLEMENTOR_H_


#include <iostream>
using namespace std;


/*
Implementor interface for Production

Used by the abstraction class, through a has-a relationship
*/
class ProductionImplementor {
public:
    virtual ~ProductionImplementor() {}
    virtual void produce(string name) = 0;
};


// Car Production
class CarProductionImplementor: public ProductionImplementor {
public:
    virtual void produce(string name) {
        printf("Production Implementor: Car: produced '%s'\n", name.c_str());
    }
};


// Truck Production
class TruckProductionImplementor: public ProductionImplementor {
public:
    virtual void produce(string name) {
        printf("Production Implementor: Truck: produced '%s'\n", name.c_str());
    }
};


#endif