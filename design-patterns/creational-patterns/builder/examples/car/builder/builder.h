#pragma once
#ifndef BUILDER_H_
#define BUILDER_H_

#include <iostream>
#include "../product/product.h"
using namespace std;


/*
Builder Interface
- Provides a common interface to be followed by all concrete builders
- Each concrete builder offers a variation in the actual product object created
*/
class CarBuilder {
public:
    virtual void setDoors(int d) = 0;
    virtual void setHorsepower(int h) = 0;
    virtual void setSeats(int s) = 0;
    virtual void setTyres(string t) = 0;
    virtual void setColor(string c) = 0;
    virtual void setDrive(string d) = 0;
    virtual void reset() = 0;
    virtual Car* getObject() = 0;
    virtual ~CarBuilder() {}
};



// Concrete Builder
class ConcreteCarBuilder: public CarBuilder {
    Car *car;
public:
    ConcreteCarBuilder() {
        car = new Car();
    }

    ~ConcreteCarBuilder() {
        delete car;
    }

    virtual void setDoors(int d) {
        car->doors = d;
    }
    virtual void setHorsepower(int h) {
        car->horsepower = h;
    }
    virtual void setSeats(int s) {
        car->seats = s;
    }
    virtual void setTyres(string t) {
        car->tyres = t;
    }
    virtual void setColor(string c) {
        car->color = c;
    }
    virtual void setDrive(string d) {
        car->drive = d;
    }
    virtual void reset() {
        car = new Car();
    }
    virtual Car* getObject() {
        return car;
    }

};


#endif