#pragma once
#ifndef TERMINAL_H_
#define TERMINAL_H_


#include <iostream>
#include <algorithm>
#include "../abstract.h"
using namespace std;


/*
Terminal Expression
- Represents a finite quantity such as number
- A Leaf in the expression tree
*/
class TerminalExpression: public AbstractExpression {
    string value;
public:
    TerminalExpression(string v) { value = v; }

    virtual int interpret(Context *c) {
        return c->getValue(value);
    }

    virtual string print() {
        return value;
    }
};



#endif