#pragma once
#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include "../treeflyweight/flyweight.h"
using namespace std;


/*
Tree Interface
- Without Flyweight, each object maintains its own state - color, name, type
- With Flyweight, each object resuses the same flyweight state
- Aggregation - contains treetype flyweight object
*/
class ITree {
public:
    virtual ~ITree() {}

    virtual void draw() = 0;
};


// Tree Concrete
class Tree: public ITree {
    int x, y;
    Flyweight *type;
public:
    ~Tree() { delete type; }
    Tree(int a, int b, Flyweight *t) { x = a, y = b, type = t; }

    virtual void draw() { type->draw(x, y); }
};


#endif