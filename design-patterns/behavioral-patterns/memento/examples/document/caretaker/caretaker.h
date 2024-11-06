#pragma once
#ifndef CARETAKER_H_
#define CARETAKER_H_

#include <iostream>
#include <stack>
#include "../originator/originator.h"
using namespace std;

/**
 * Caretaker Concrete
 * Keeps track of all previous internal states
 */
class Caretaker {
    stack<Memento*> snapshots;
    DocumentOriginator *originator;
public:
    Caretaker(DocumentOriginator *orig) { originator = orig; }

    void saveState() {
        printf("Caretaker: /saveState called\n");

        snapshots.push(originator->saveState());
    }
    void restore() {
        printf("Caretaker: /restore called\n");

        Memento *rest = snapshots.top(); snapshots.pop();
        printf("Caretaker: restored state with metadata: %s\n", rest->getMetadata().c_str());
        originator->restore(rest);
    }
};

#endif