#include <iostream>
#include "handler/handler.h"

using namespace std;

// Client and Driver Code
int main() {
    cout<<"Starting the code\n";

    LogHandler *infoLogProcessor = new InfoHandler();
    LogHandler *debugLogProcessor = new DebugHandler();
    LogHandler *errorLogProcessor = new ErrorHandler();
    LogHandler *defaultLogProcessor = new DefaultHandler();

    infoLogProcessor->setNext(debugLogProcessor);
    debugLogProcessor->setNext(errorLogProcessor);
    errorLogProcessor->setNext(defaultLogProcessor);
    
    cout<<"Built the sequence\n";

    infoLogProcessor->log(Level::ERROR);
    debugLogProcessor->log(Level::DEBUG);
    debugLogProcessor->log(Level::INFO);


    return 0;
}