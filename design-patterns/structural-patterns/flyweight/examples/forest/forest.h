#pragma once
#ifndef FOREST_H_
#define FOREST_H_

#include <iostream>
#include <vector>
#include "tree/tree.h"
#include "treeflyweight/factory.h"
using namespace std;



/*
Forest Concrete Class
- Aggregation with the Tree Class, TreeType Factory
- addTree with all parameters - both intrinsic and extrinsic
- use the factory to retrieve back already created intrinsic parameters
*/
class Forest {
    vector<ITree*> treeList;
    FlyweightFactory *factory;
public:
    Forest(FlyweightFactory *fact) { factory = fact; }
    ~Forest() { delete factory; }

    void addTree(int x, int y, string color, string type, string name) {
        printf("Forest: Add Tree: %s\n", (color + "-" + type + "-" + name).c_str());
        Flyweight *treeType = factory->getOrCreate(color, type, name);
        ITree *newTree = new Tree(x, y, treeType);
        treeList.push_back(newTree);
    }

    void draw() {
        for (auto &t: treeList) {
            t->draw();
        }
    }
};


#endif