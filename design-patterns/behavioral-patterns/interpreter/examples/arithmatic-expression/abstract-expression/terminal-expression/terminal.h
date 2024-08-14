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
    int value;
    
    string stringify(int val) {
        string ret = "";
        
        if (val == 0)
            return "0";

        while (val > 0) {
            ret += '0' + (val % 10);
            val /= 10;
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
public:
    TerminalExpression(int v) { value = v; }

    virtual int interpret() {
        return value;
    }

    virtual string print() {
        return stringify(value);
    }
};



#endif