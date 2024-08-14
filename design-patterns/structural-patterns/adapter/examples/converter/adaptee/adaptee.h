#pragma once
#ifndef ADAPTEE_H_
#define ADAPTEE_H_

#include <iostream>
using namespace std;

/*
Adaptee Concrete class
or
Service which is incompatible to our client
*/
class Adaptee {
public:
    char* response(const char* request) {
        printf("Adaptee: Received Request: (char*) '%s'\n", request);

        char *response = "a response from service for request";
        return response;
    }
};


#endif