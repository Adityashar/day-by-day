#pragma once
#ifndef CONTEXT_H_
#define CONTEXT_H_


#include <iostream>
#include <unordered_map>
using namespace std;

/*
Context Class
Provide a "context" or information to the interpreter class and the expression trees
*/
class Context {
    unordered_map<string, int> store;
public:
    void setValue(string key, int value) { store[key] = value; }
    int getValue(string key) { return store[key]; }
};


#endif