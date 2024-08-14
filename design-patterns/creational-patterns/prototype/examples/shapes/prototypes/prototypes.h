#pragma once
#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_


#include <iostream>

using namespace std;



/*
A Shape Abstract Class
With a Clone() and a Copy Constructor
-> Prototype
*/
class Shape {
protected:
    string color;
public:
    Shape(string c) {
        color = c;
    }
    Shape(Shape *s) {
        color = s->color;
    }

    virtual double area() = 0;
    virtual Shape* clone() = 0;
    virtual string getColor() = 0;
    virtual ~Shape() {}
};


// Square Concrete Class of the Prototype
class Square: public Shape {
    int x;
public:
    Square(int a, string c): Shape(c) {
        x = a;
    }

    Square(Square *s): Shape(s) {
        x = s->x;
    }

    virtual double area() {
        return x * x;
    }

    virtual string getColor() {
        return this->color;
    }

    virtual Square* clone() {
        return new Square(this);
    }
};


// Circle Concrete Class of the Prototype
class Circle: public Shape {
    int r;
public:
    Circle(int a, string c): Shape(c) {
        r = a;
    }

    Circle(Circle *s): Shape(s) {
        r = s->r;
    }

   virtual double area() {
        return r * r * 3.14;
    }

    virtual string getColor() {
        return this->color;
    }

    virtual Circle* clone() {
        return new Circle(this);
    }
};


#endif