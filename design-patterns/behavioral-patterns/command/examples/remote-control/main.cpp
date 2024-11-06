#include <iostream>
#include "invoker/invoker.h"
using namespace std;


int main() {

    // AC Receiver
    IReceiver *device1 = new AcReceiver();
    // TV Receiver
    IReceiver *device2 = new TvReceiver();

    // Invoker
    Invoker *remote = new Invoker();


    // Commands
    ICommand *cmd1 = new TurnOnCommand(device1);
    ICommand *cmd2 = new TurnOnCommand(device2);
    ICommand *cmd3 = new ChangeModeCommand(device1, "power");

    remote->setCommand(cmd1);
    remote->pressButton();

    remote->setCommand(cmd2);
    remote->pressButton();

    remote->setCommand(cmd3);
    remote->pressButton();

    remote->undoButton();
    remote->undoButton();
    remote->undoButton();

    return 0;
}