#pragma once
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include<iostream>
using namespace std;

/*

An Interface to represent a base file

With methods to
- Read file
- Write file

*/
class IComponent {
public:
    virtual ~IComponent() {}
    virtual string read() = 0;
    virtual void write(string data) = 0;
    virtual string getName() = 0;
};


/*
FileComponent Concrete class to implement the Component Interface
*/
class FileComponent: public IComponent {
    string fileName;
    string data;
public:
    FileComponent(string name) {
        this->fileName = name;
        this->data = "";
    }

    virtual string read();
    virtual void write(string data);
    virtual string getName() {
        return fileName;
    }
};


#endif