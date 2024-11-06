#pragma once
#ifndef COLLEAGUE_H_
#define COLLEAGUE_H_


#include<iostream>
#include "interface.h"
#include "../mediator/mediator.h"
using namespace std;


// Airbus Airplane
class AirbusColleague: public AirplaneColleague {
    Mediator *ATC;
public:
    AirbusColleague(Mediator *atc): ATC(atc) {
        atc->add(this);
    }

    virtual void notifyLanding() { ATC->notifyLanding(this); }
    virtual void notifyTakeOff() { ATC->notifyTakeOff(this); }
    virtual void notify(string msg) {
        printf("Airbus Colleague: Msg Received: %s", msg.c_str());
    }
};


// Boeing Airplane
class BoeingColleague: public AirplaneColleague {
    Mediator *ATC;
public:
    BoeingColleague(Mediator *atc): ATC(atc) {
        atc->add(this);
    }

    virtual void notifyLanding() { ATC->notifyLanding(this); }
    virtual void notifyTakeOff() { ATC->notifyTakeOff(this); }
    virtual void notify(string msg) {
        printf("Boeing Colleague: Msg Received: %s", msg.c_str());
    }
};

#endif