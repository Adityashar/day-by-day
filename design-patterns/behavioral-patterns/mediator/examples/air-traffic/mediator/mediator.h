#pragma once
#ifndef MEDIATOR_H_
#define MEDIATOR_H_


#include <iostream>
#include <vector>
#include "../colleague/interface.h"
using namespace std;


/**
 * Mediator Interface
 * ATC Mediator coordinates and controls the interaction or communication amongst the colleagues
 */
class Mediator {
public:
    virtual void notifyLanding(AirplaneColleague *c) = 0;
    virtual void notifyTakeOff(AirplaneColleague *c) = 0;

    virtual void add(AirplaneColleague *c) {}

    virtual ~Mediator() {}
};


// ATC Mediator
class AtcMediator: public Mediator {
    vector<AirplaneColleague*> colleagues;
public:
    AtcMediator() {}

    virtual void add (AirplaneColleague *c) {
        printf("ATC: Added airplane colleague\n");
        colleagues.push_back(c);
    }

    virtual void notifyLanding(AirplaneColleague *ac) { 
        for (auto &c: colleagues) {
            if (ac != c) {
                c->notify("ATC: Airplane Landing\n");
            }
        }
    }
    virtual void notifyTakeOff(AirplaneColleague *ac) {
        for (auto &c: colleagues) {
            if (ac != c) {
                c->notify("ATC: Airplane TakeOff\n");
            }
        }
    }
};



#endif