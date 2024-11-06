#pragma once
#ifndef ABSTRACT_H_
#define ABSTRACT_H_


#include <iostream>
#include "../context/context.h"
using namespace std;


/*
An Interface for the Abstract Expressions
- This is a common interface for Terminal and Non-Terminal Expressions
- Contains the interpret() to evaluate the expression trees or the expression hierarchy
*/
class AbstractExpression {
public:
    virtual ~AbstractExpression() {}

    virtual int interpret(Context *c) = 0;
    virtual string print() = 0;
};



#endif