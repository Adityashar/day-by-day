#pragma once
#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
#include <unordered_map>
#include "flyweight.h"
using namespace std;


/*
Factory Interface
*/
class FlyweightFactory {
public:
    virtual ~FlyweightFactory() {}

    virtual Flyweight* getOrCreate(string color, string type, string name) = 0;
};

/*
TreeType Concrete Factory
- Aggregation - Has a cache of already created objects 
*/
class TreeTypeFactory: public FlyweightFactory {
    unordered_map<string, Flyweight*> flyweightCache;
public:
    void resetCache() { flyweightCache.clear(); }

    virtual Flyweight* getOrCreate(string color, string type, string name) {
        string key = color + "-" + type + "-" + name;

        if (flyweightCache.find(key) != flyweightCache.end())
            return flyweightCache[key];
        
        printf("Cache Miss: Create Tree Type: %s\n", (color + "-" + type + "-" + name).c_str());

        Flyweight *fw = new TreeType(name, color, type);
        flyweightCache[key] = fw;
        return fw;
    }
};


#endif