#pragma once
#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

/*
A Concrete Product
*/
class Car {
public:
    int doors;
    int horsepower;
    int seats;
    string tyres;
    string color;
    string drive;

    void display() {
        printf("Doors: %d, Horsepower: %d, Seats: %d, Tyres: %s, Color: %s, Drive: %s\n",
            doors,
            horsepower,
            seats,
            tyres.c_str(),
            color.c_str(),
            drive.c_str()
        ); 
    }
};

#endif