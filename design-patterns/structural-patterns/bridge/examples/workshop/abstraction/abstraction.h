#pragma once
#ifndef ABSTRACTION_H_
#define ABSTRACTION_H_


#include <iostream>
#include "../implementer/implementor.h"
using namespace std;


/*
A  high level entity exposed to the client without any implementation details
Maintains a has-a relationship with the implemetors
*/
class VehicleAbstraction {
public:
    virtual void build () = 0;
    virtual ~VehicleAbstraction() {}
};


// Car Abstraction
class CarAbstraction: public VehicleAbstraction {
    ProductionImplementor *pi;
    AssemblyImplementor   *ai;
    string name;
public:
    CarAbstraction(ProductionImplementor *imp1, AssemblyImplementor *imp2, string name) {
        pi = imp1;
        ai = imp2;
        this->name = name;
    }
    virtual void build() {
        printf("Vehicle Absraction: Car: Building '%s'\n", this->name.c_str());
        ai->assemble(name);
        pi->produce(name);
    }
    ~CarAbstraction() {
        delete pi;
        delete ai;
    }
};


// Truck Abstraction
class TruckAbstraction: public VehicleAbstraction {
    ProductionImplementor *pi;
    AssemblyImplementor   *ai;
    string name;
public:
    TruckAbstraction(ProductionImplementor *imp1, AssemblyImplementor *imp2, string name) {
        pi = imp1;
        ai = imp2;
        this->name = name;
    }
    virtual void build() {
        printf("Vehicle Absraction: Truck: Building '%s'\n", name.c_str());
        ai->assemble(name);
        pi->produce(name);
    }
    ~TruckAbstraction() {
        delete pi;
        delete ai;
    }
};

#endif