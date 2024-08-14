#pragma once
#ifndef FACADE_H_
#define FACADE_H_

#include <iostream>
#include <vector>
#include "../worker/worker.h"
using namespace std;



/*
Facade Interface
- Set of methods that extract / focusses on a specific functionality of the SubSystem
*/
class Facade {
public:
    virtual ~Facade() {}

    virtual void workday() = 0;
};

// Facade Concrete
class MineFacade: public Facade {
    vector<Worker*> workers;

public:
    MineFacade(vector<Worker*> w) {
        workers = w;
    }

    virtual void workday() {
        printf("Facade: Daily Routine\n");
        for (auto &w: workers)
            w->getToWork();

        for (auto &w: workers)
            w->work();
        
        for (auto &w: workers)
            w->goHome();
    }
};


#endif