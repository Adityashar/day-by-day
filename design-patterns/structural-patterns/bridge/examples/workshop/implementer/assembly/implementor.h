#pragma once
#ifndef A_IMPLEMENTOR_H_
#define A_IMPLEMENTOR_H_


#include <iostream>
using namespace std;

/*
Implementor interface for Assembly

Used by the abstraction using a has-a relationship
*/
class AssemblyImplementor {
public:
    virtual ~AssemblyImplementor() {}
    virtual void assemble(string name) = 0;
};


// Car Assembly
class CarAssemblyImplementor: public AssemblyImplementor {
public:
    virtual void assemble(string name) {
        printf("Assembly Implementor: Car: assembled '%s'\n", name.c_str());
    }
};


// Truck Assembly
class TruckAssemblyImplementor: public AssemblyImplementor {
public:
    virtual void assemble(string name) {
        printf("Assembly Implementor: Truck: assembled '%s'\n", name.c_str());
    }
};


#endif