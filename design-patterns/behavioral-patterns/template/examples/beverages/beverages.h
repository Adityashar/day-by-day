#pragma once
#ifndef BEVERAGES_H_
#define DEVERAGES_H_

#include <iostream>
using namespace std;

/*
Template Method Abstract Class
1. Contains virtual methods to be overridden
2. One (or more) methods with a fixed algorithm or steps
*/
class BeverageMaker {
public:
    void makeBeverage() {
        addWater();
        boilWater();
        addCondiments();
        addMilk();
        serve();
    }

    virtual ~BeverageMaker() {}

    // Common
    virtual void addWater() { printf("Adding Water\n"); }
    virtual void boilWater() { printf("Boiling Water\n"); }
    
    // Unique
    virtual void addCondiments() = 0;
    virtual void addMilk() = 0;
    virtual void serve() = 0;
};


// Coffee Beverage
class CoffeeMaker: public BeverageMaker {
    string name;
public:
    CoffeeMaker(string n) { name = n; }

    virtual void addCondiments() {
        printf("Adding Coffee\n");
        printf("Adding Sugar\n");
    }
    virtual void addMilk() {
        printf("Adding Soy Milk\n");
    }
    virtual void serve() {
        printf("Serving in a Coffee Mug\n");
    }
};


// Tea Beverage
class TeaMaker: public BeverageMaker {
    string name;
public: 
    TeaMaker(string n) { name = n; }

    virtual void addCondiments() {
        printf("Adding Tea leaves\n");
        printf("Adding Sugar\n");
    }
    virtual void addMilk() {
        printf("Adding Almond Milk\n");
    }
    virtual void serve() {
        printf("Straining and serving in a Tea Cup\n");
    }
};


#endif