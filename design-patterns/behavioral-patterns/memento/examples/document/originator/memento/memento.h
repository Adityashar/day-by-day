#pragma once
#ifndef MEMENTO_H_
#define MEMENTO_H_

#include <iostream>
using namespace std;

/**
 * Memento Interface
 * - Exposes only specific set of functions
 * - State is immutable and abstracted to all execpt originator
 */
class Memento {
public:
    virtual string getMetadata() = 0;

    virtual ~Memento() { }
};



/**
 * Concrete Memento
 */
class DocumentMemento: public Memento {
    string state;
    string metadata;
public:
    DocumentMemento(string state, string metadata) {
        printf("Memento: /create called\n");
        this->state = state;
        this->metadata = metadata; 
    }

    virtual string getMetadata() {
        printf("Memento: /getMetadata called\n");
        return metadata;
    } 

    string getState() {
        printf("Memento: /getState called\n");
        return state;
    }
};

#endif