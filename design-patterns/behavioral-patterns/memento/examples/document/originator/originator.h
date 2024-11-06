#pragma once
#ifndef ORIGINATOR_H_
#define ORIGINATOR_H_

#include "memento/memento.h"
#include <iostream>
#include <ctime>
using namespace std;

/**
 * Originator Concrete
 * Performs some work and has a state
 */
class DocumentOriginator {
    string state;

    string now() {
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);

        string s(buffer);

        return s;
    }

public:
    DocumentOriginator(string initState) { state = initState; }

    void doWork(string input) {
        printf("Originator: Working on Document\n");
        state = input;
    }

    Memento* saveState() {
        printf("Originator: /saveState called\n");
        string metadata = now();
        return new DocumentMemento(state, metadata);
    }

    void restore(Memento* snapshot) {
        printf("Originator: /restore called\n");
        DocumentMemento *documentSnapshot = dynamic_cast<DocumentMemento*>(snapshot);
        this->state = documentSnapshot->getState();
    }
};

#endif