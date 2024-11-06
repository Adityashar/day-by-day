#pragma once
#ifndef RECEIVER_H_
#define RECEIVER_H_


#include <iostream>
using namespace std;


/*
Receiver Interface
Common methods for all receivers used in the Commands
*/
class IReceiver {
public:
    virtual ~IReceiver() { }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void changeMode(string newMode) = 0;
};


// AC Implementation
class AcReceiver: public IReceiver {
    bool on;
    string mode;
public:
    AcReceiver() { on = 0, mode = "default"; }

    virtual void turnOn() {
        printf("Turned On the AC\n");
        on = 1;
    }

    virtual void turnOff() {
        printf("Turned Off the AC\n");
        on = 0;
    }

    virtual void changeMode(string newMode) {
        printf("Changed Mode from '%s' to '%s' on the AC\n", mode.c_str(), newMode.c_str());
        mode = newMode;
    }
};


// TV Implementation
class TvReceiver: public IReceiver {
    bool on;
    string mode;
public:
    TvReceiver() { on = 0, mode = "default"; }

    virtual void turnOn() {
        printf("Turned On the TV\n");
        on = 1;
    }

    virtual void turnOff() {
        printf("Turned Off the TV\n");
        on = 0;
    }

    virtual void changeMode(string newMode) {
        printf("Changed Mode from '%s' to '%s' on the TV\n", mode.c_str(), newMode.c_str());
        mode = newMode;
    }
};


#endif