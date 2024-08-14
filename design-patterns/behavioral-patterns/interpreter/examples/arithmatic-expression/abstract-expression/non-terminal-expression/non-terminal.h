#pragma once
#ifndef NON_TERMINAL_H_
#define NON_TERMINAL_H_


#include <iostream>
#include <algorithm>
#include "../abstract.h"
using namespace std;



/*
Non-Terminal Expression Abstract Class
- These represents rules in a specific grammar
- If we take the example on the arithmatic expression, then +, -, /, * would be our Non-Terminal Expressions
- Each non-terminal expression has-two abstract expression objects, which represents the left and right subtrees of expression trees
*/
class NonTerminalExpression: public AbstractExpression {
    AbstractExpression *leftExpression;
    AbstractExpression *rightExpression;
    string rule;
public:
    NonTerminalExpression(AbstractExpression *l, AbstractExpression *r, string input) { leftExpression = l, rightExpression = r; rule = input; }
    ~NonTerminalExpression() { delete leftExpression, rightExpression; }

    virtual string print() {
        string left = leftExpression->print();
        string right = rightExpression->print();

        return left + rule + right;
    }

    AbstractExpression* getLeftExpression() { return leftExpression; }
    AbstractExpression* getRightExpression() { return rightExpression; }
};


// Addition Expression
class AdditionExpression: public NonTerminalExpression {
public:
    AdditionExpression(AbstractExpression *l, AbstractExpression *r): NonTerminalExpression(l, r, "+") {}
    
    virtual int interpret() {
        int left = getLeftExpression()->interpret();
        int right = getRightExpression()->interpret();

        // Addition
        return left + right;
    }
};


// Multiply Expression
class MultiplyExpression: public NonTerminalExpression {
public:
    MultiplyExpression(AbstractExpression *l, AbstractExpression *r): NonTerminalExpression(l, r, "*") {}
    
    virtual int interpret() {
        int left = getLeftExpression()->interpret();
        int right = getRightExpression()->interpret();

        // Multipy
        return left * right;
    }
};


// Subtract Expression
class SubtractExpression: public NonTerminalExpression {
public:
    SubtractExpression(AbstractExpression *l, AbstractExpression *r): NonTerminalExpression(l, r, "-") {}
    
    virtual int interpret() {
        int left = getLeftExpression()->interpret();
        int right = getRightExpression()->interpret();

        // Multipy
        return left - right;
    }
};


#endif