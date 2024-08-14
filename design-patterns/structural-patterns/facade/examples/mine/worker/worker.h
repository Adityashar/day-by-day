#pragma once
#ifndef WORKER_H_
#define WORKER_H_

#include <iostream>
#include "../machine/machine.h"
using namespace std;


// Worker Interface
class Worker {

public:
    virtual ~Worker() {}

    virtual void getToWork() = 0;
    virtual void work() = 0;
    virtual void goHome() = 0;
    virtual string getName() = 0;
};


// Gold Worker
class GoldWorker: public Worker {
    string name;
    Machine *mach;
public:
    GoldWorker(string n) {
        name = n;
        mach = new GoldMachine();
    }

    virtual void getToWork() { printf("Worker: Gold: Going to Work: '%s'\n", name.c_str()); }
    virtual void work() { mach->run(); }
    virtual void goHome() { mach->stop(); printf("Worker: Gold: Going Home: '%s'\n", name.c_str()); }
    virtual string getName() { return name; }
};


// Tunnel Worker
class TunnelWorker: public Worker {
    string name;
    Machine *mach;
public:
    TunnelWorker(string n) {
        name = n;
        mach = new TunnelMachine();
    }

    virtual void getToWork() { printf("Worker: Tunnel: Going to Work: '%s'\n", name.c_str()); }
    virtual void work() { mach->run(); }
    virtual void goHome() { mach->stop(); printf("Worker: Tunnel: Going Home: '%s'\n", name.c_str()); }
    virtual string getName() { return name; }
};


#endif