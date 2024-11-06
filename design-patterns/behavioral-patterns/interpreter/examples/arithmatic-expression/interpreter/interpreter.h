#pragma once
#ifndef INTERPRETER_H_
#define INTERPRETER_H_


#include <iostream>
#include <stack>
#include "../abstract-expression/abstract.h"
#include "../abstract-expression/terminal-expression/terminal.h"
#include "../abstract-expression/non-terminal-expression/non-terminal.h"
using namespace std;

/*
Interpreter Class
- Contains the Context
- Builds the expression tree based on input from client
- Calls the interpret method
*/
class Interpretor {
    Context *c;
    AbstractExpression *exp;
    
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*';
    }
public:
    Interpretor(Context *con) { c = con; }

    // postfix string expression !! 
    void buildExpression(string expression) {
        stack<AbstractExpression*> exps;

        for (int i=0; i<expression.size(); i++) {
            if (isOperator(expression[i])) {
                AbstractExpression *exp1 = exps.top(); exps.pop();
                AbstractExpression *exp2 = exps.top(); exps.pop();
                
                AbstractExpression *non;

                switch (expression[i]) {
                case '+':
                    non = new AdditionExpression(exp1, exp2);
                    break;
                case '-':
                    non = new SubtractExpression(exp1, exp2);
                    break;
                case '*':
                    non = new MultiplyExpression(exp1, exp2);
                    break;
                default:
                    cout<<"ERROR: invalid charactor"<<expression[i]<<endl;
                    exit(1);
                }

                exps.push(non);
            } else {
                string s = ""; s += expression[i];
                AbstractExpression *abs = new TerminalExpression(s);
                exps.push(abs);
            }
        }

        this->exp = exps.top();
        exps.pop();
    }

    int interpretExpression() {
        return exp->interpret(c);
    }

    string displayExpression() {
        return exp->print();
    }
};


#endif