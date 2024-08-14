#pragma once
#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include <iostream>
using namespace std;

/*
TreeType Flyweight Interface
1. Contains a set of methods to be used in the flyweight concrete class
2. Some of the methods are parameterized to accept extrinsic members of the class object

*/
class Flyweight {
public:
    virtual ~Flyweight() {}

    virtual void draw(int x, int y) = 0;
    virtual void display() = 0;
};


// TreeType Class
class TreeType: public Flyweight {
    string color;
    string type;
    string name;
public:
    TreeType(string n, string c, string t) { color = c, type = t, name = n; }

    virtual void draw(int x, int y) {
        printf("Drawing @ X='%d', Y='%d': ", x, y);
        display();
    }

    virtual void display() {
        printf("TreeType: name='%s', color='%s', type='%s'\n", name.c_str(), color.c_str(), type.c_str());
    }
};


#endif