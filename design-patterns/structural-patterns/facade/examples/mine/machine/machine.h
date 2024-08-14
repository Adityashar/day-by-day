#pragma once
#ifndef MACHINE_H_
#define MACHINE_H_


#include <iostream>
using namespace std;


/*
Machine Interface
*/
class Machine {
public:
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual void repair() = 0;
    virtual string getName() = 0;

    virtual ~Machine() {}
};


// Tunnel Machine Concrete Class
class TunnelMachine: public Machine {
    string name;
public:
    TunnelMachine() { name = "TunnelMachine"; }
    
    virtual void run() { printf("Machine: Running: '%s'\n", name.c_str()); }
    virtual void stop() { printf("Machine: Stopping: '%s'\n", name.c_str()); }
    virtual void repair() { printf("Machine: Repairing: '%s'\n", name.c_str()); }
    virtual string getName() { return name; }
};


// Gold Extractor Machine Concrete Class
class GoldMachine: public Machine {
    string name;
public:
    GoldMachine() { name = "GoldMachine"; }
    
    virtual void run() { printf("Machine: Running: '%s'\n", name.c_str()); }
    virtual void stop() { printf("Machine: Stopping: '%s'\n", name.c_str()); }
    virtual void repair() { printf("Machine: Repairing: '%s'\n", name.c_str()); }
    virtual string getName() { return name; }
};

#endif