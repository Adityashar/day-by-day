#pragma once
#ifndef HANDLER_H_
#define HANDLER_H_


#include <iostream>
using namespace std;

// enum
enum Level {
    INFO = 0,
    DEBUG = 1,
    ERROR = 2,
};

/*
LogHandler Abstract Class
Common standard for all handlers
*/
class LogHandler {
protected:
    LogHandler* nextHandler;
public:
    LogHandler() {}

    virtual ~LogHandler() { delete nextHandler; }
    virtual void log(Level level) = 0;

    void setNext(LogHandler *h) { nextHandler = h; }
};


// InfoLogHandler
class InfoHandler: public LogHandler {
public:
    InfoHandler() { }

    virtual void log(Level level) {
        if (level == Level::INFO) {
            printf("INFO: Printing with at info level\n");
        } else {
            nextHandler->log(level);
        }
    }
};


// DebugLogHandler
class DebugHandler: public LogHandler {
public:
    DebugHandler() { }

    virtual void log(Level level) {
        if (level == Level::DEBUG) {
            printf("DEBUG: Printing with at debug level\n");
        } else {
            nextHandler->log(level);
        }
    }
};


// ErrorLogHandler
class ErrorHandler: public LogHandler {
public:
    ErrorHandler() { }

    virtual void log(Level level) {
        if (level == Level::ERROR) {
            printf("ERROR: Printing with at error level\n");
        } else {
            nextHandler->log(level);
        }
    }
};


// DefaultLogHandler
class DefaultHandler: public LogHandler {
public:
    DefaultHandler() { }

    virtual void log(Level level) {
        printf("Default: Printing with at default level\n");
    }
};


#endif
