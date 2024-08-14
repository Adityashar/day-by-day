#pragma once
#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "sorting.h"
using namespace std;

// Context Class
/*
Allows strategy selection at runtime
based on inputs or needs of the client

Keeps an Object of type Strategy Interface

Based on the input from client, this object
is updated to the respective strategy
*/

class SortingContext {
public:
    // Has "a" object of SortingStrategy
    SortingStrategy *sorting;

    SortingContext(SortingStrategy *input) {
        this->sorting = input;
        printf("Context: Updated context to %s..\n", input->name.c_str());
    }

    void SetSortingContext(SortingStrategy *input);
    string GetSortingContext();
};

#endif