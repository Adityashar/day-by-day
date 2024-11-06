#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_


#include <iostream>
#include "../receiver/receiver.h"
using namespace std;


/*
Command Interface
Set of common methods for all commands
*/
class ICommand {
public:
    virtual ~ICommand() { }

    virtual void execute() = 0;
    virtual void undo() = 0;
};


// Turn On Command
class TurnOnCommand: public ICommand {
    IReceiver *device;
public:
    TurnOnCommand(IReceiver *inputDevice) { device = inputDevice; }
    ~TurnOnCommand() { delete device; }

    virtual void execute() { 
        printf("Execute TurnOn Command\n");
        device->turnOn();
    }
    virtual void undo() {
        printf("Undo TurnOn Command\n");
        device->turnOff();
    }
};


// Turn Off Command
class TurnOffCommand: public ICommand {
    IReceiver *device;
public:
    TurnOffCommand(IReceiver *inputDevice) { device = inputDevice; }
    ~TurnOffCommand() { delete device; }

    virtual void execute() { 
        printf("Execute TurnOff Command\n");
        device->turnOff();
    }
    virtual void undo() {
        printf("Undo TurnOn Command\n");
        device->turnOn();
    }
};


// Change Mode Command
class ChangeModeCommand: public ICommand {
    IReceiver *device;
    string mode;
public:
    ChangeModeCommand(IReceiver *inputDevice, string newMode) { device = inputDevice, mode = newMode; }
    ~ChangeModeCommand() { delete device; }

    virtual void execute() { 
        printf("Execute ChangeMode Command\n");
        device->changeMode(mode);
    }
    virtual void undo() {
        printf("Undo ChangeMode Command\n");
        device->changeMode("default");
    }
};

#endif