#pragma once
#ifndef PROXY_H_
#define PROXY_H_

#include <iostream>
#include <vector>
#include "../subject/subject.h"

using namespace std;


/*
Proxy 
- Implements the Subject interface
- Maintains an object of Subject Interface
- Uses the object to make calls towards the real methods
*/
class LibraryProxy: public ISubject {
    ISubject *realLibrary;
    string user;

    bool checkAccess() {
        return user == "admin";
    }

public:
    LibraryProxy(ISubject *obj, string access) {
        realLibrary = obj;
        user = access;
    }

    ~LibraryProxy() {
        delete realLibrary;
    }

    // Cant add
    // We are using the ISubject interface object for runtime polymorphism
    // So only those methods could be used
    void setAccess(string access) {
        user = access;
    }

    virtual void add(string book) {
        if (checkAccess()) {
            realLibrary->add(book);
        } else {
            printf("Proxy: Blocked '%s'\n", user.c_str());
        }
    }

    virtual void remove(string book) {
        if (checkAccess()) {
            realLibrary->remove(book);
        } else {
            printf("Proxy: Blocked '%s'\n", user.c_str());
        }
    }

    virtual vector<string> list() {
        return realLibrary->list();
    }
    virtual string getName() {
        return realLibrary->getName();
    }
};


#endif