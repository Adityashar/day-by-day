#pragma once
#ifndef OBSERVER_H_
#define OBSERVER_H_

#include<iostream>
using namespace std;

// Observer Interface
class Observer {
    virtual void performBusinessLogin() = 0;
public:
    string name;
    string state;
    virtual void update(string newState) = 0;
};


/////////////////////
/////////////////////


// LocalObserver Concrete Class
class LocalObserver: public Observer {
    void performBusinessLogin() {
        printf("LOCAL: Performing business logic of %s due to new state %s of Publisher\n", this->name.c_str(), this->state.c_str());
    }
public:
    LocalObserver() {
        this->name = "LOCAL";
        this->state = "NOT_UPDATED";
    }
    void update(string newState) {
        this->state = newState;
        performBusinessLogin();
    }
};


// PrintObserver Concrete Class
class PrintObserver: public Observer {
    void performBusinessLogin() {
        printf("PRINT: Performing business logic of '%s' due to new state '%s' of Publisher\n", this->name.c_str(), this->state.c_str());
    }
public:
    PrintObserver() {
        this->name = "PRINT";
        this->state = "NOT_UPDATED";
    }
    void update(string newState) {
        this->state = newState;
        performBusinessLogin();
    }
};


#endif