#pragma once
#ifndef TARGET_H_
#define TARGET_H_

#include <iostream>
#include "../adaptee/adaptee.h"
using namespace std;

/*
Target Interface
- Common interface for our client class and our adapter
- adapter shall contain methods to convert incoming data into a suitable form for the adaptee
*/
class Target {
public:
    virtual ~Target() {}
    virtual string response(string request) = 0;
};


// Adapter Concrete class
class Adapter: public Target {
    // An object of Adaptee Concrete class or Interface
    // To call original methods
    // Similar of Proxy, Decorator
    Adaptee *service;
public:
    Adapter(Adaptee *input) {
        service = input;
    }
    virtual string response(string request) {
        printf("Adapter: Received Request: (string) '%s'\n", request.c_str());
        return string(service->response(request.c_str()));
    }
};

#endif