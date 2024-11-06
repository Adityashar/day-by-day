#pragma once
#ifndef I_COLLEAGUE_H_
#define I_COLLEAGUE_H_

#include <iostream>

/**
 * Colleague Interface
 * Airplane acts as a colleague in our usecase
 */
class AirplaneColleague {
public:
    virtual void notifyLanding() = 0;
    virtual void notifyTakeOff() = 0;
    virtual void notify(std::string msg) = 0;

    virtual ~AirplaneColleague() { }
};


#endif