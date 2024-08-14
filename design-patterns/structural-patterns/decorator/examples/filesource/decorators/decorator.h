#pragma once
#ifndef DECORATOR_H_
#define DECORATOR_H_


#include<iostream>
#include "../component/component.h"
using namespace std;


/*
Decorator Interface / Abstract Class / Concrete Class
- Extends Component Interace
- Keeps an object of Component Interface ('has - a' aggregation)

Uses the object to call methods of already decorated classes, up the stack
*/
class IDecorator: public IComponent {
    string name;
protected:
    IComponent *file;
public:
    IDecorator(IComponent *inputFile) {
        file = inputFile;
        name = "base";
    }
    virtual string getName() {
        return name + "(" + file->getName() + ")";
    }
    virtual string read() {
        return file->read();
    }
    virtual void write(string data) {
        file->write(data);
    }
};


/*
Compression Decorator
- When writing, first compress and then write
- When reading, first read and then decompress
*/
class CompressionDecorator: public IDecorator {
    string compress(string data) {
        return "<<" + data + ">>";
    }
    string decompress(string data) {
        return data.substr(2, data.size()-4);
    }
    string name;
public:
    CompressionDecorator(IComponent *inputFile): IDecorator(inputFile) {
        name = "Compression";
    }
    virtual string getName() {
        return name + "(" + file->getName() + ")";
    }
    virtual string read() {
        return this->decompress(file->read());
    }
    virtual void write(string data) {
        file->write(this->compress(data));
    }
};

/*
Encrypting Decorator
- When writing, first encrypt and then write
- When reading, first read and then decrypt
*/
class EncryptionDecorator: public IDecorator {
    string encrypt(string data) {
        return "EE" + data + "EE";
    }
    string decrypt(string data) {
        return data.substr(2, data.size()-4);
    }
    string name;
public:
    EncryptionDecorator(IComponent *inputFile): IDecorator(inputFile) {
        name = "Encrypting";
    }
    virtual string read() {
        return this->decrypt(file->read());
    }
    virtual void write(string data) {
        file->write(this->encrypt(data));
    }
    virtual string getName() {
        return name + "(" + file->getName() + ")";
    }
};

#endif