#pragma once
#ifndef INVOKER_H_
#define INVOKER_H_


#include <iostream>
#include <stack>
#include "../command/command.h"
using namespace std;


/*
Sender or the Remote
*/
class Invoker {
    ICommand *cmd;
    stack<ICommand*> history;
public:
    void setCommand(ICommand *input) { 
        printf("Set Invoker Command\n");
        cmd = input; 
    }

    void pressButton() {
        printf("Pressed Button\n");
        cmd->execute();
        history.push(cmd);
    }

    void undoButton() {
        printf("Undo Button\n");
        ICommand *top = history.top(); history.pop();
        top->undo();
    }
};


#endif