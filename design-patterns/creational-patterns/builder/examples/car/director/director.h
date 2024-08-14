#pragma once
#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <iostream>
#include "../builder/builder.h"
using namespace std;


/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration. Strictly speaking, the Director class is
 * optional, since the client can control builders directly.
 */
class CarBuilderDirector {
    CarBuilder *cb;
public:
    ~CarBuilderDirector() {
        delete cb;
    }
    CarBuilderDirector(CarBuilder *input) {
        cb = input;
    }
    void setCarBuilder(CarBuilder *input) {
        cb = input;
    }
    void buildSedan(int doors, int hp, int seats, string tyres, string color, string drive) {
        cb->setHorsepower(hp);
        cb->setDrive(drive);
        cb->setSeats(seats);
        cb->setDoors(doors);
        cb->setTyres(tyres);
        cb->setColor(color);
    }
    void buildSUV(int doors, int hp, int seats, string tyres, string color, string drive) {
        cb->setHorsepower(hp);
        cb->setDrive(drive);
        cb->setSeats(seats);
        cb->setDoors(doors);
        cb->setTyres(tyres);
        cb->setColor(color);
    }
};


#endif