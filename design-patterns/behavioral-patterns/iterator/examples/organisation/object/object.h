#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
using namespace std;

// A Simple Object
// We define a collection for this Object
class PersonObject {
    string name;
    string parent;
public:
    PersonObject(string n, string t) { name = n, parent = t; }

    string getName() { return name; }
    string getParent() { return parent; }
};

/*
N-Ary Tree Data Structure
*/
class Node {
public:    
    PersonObject *person;
    vector<Node*> children;

    Node (string name, string parent) {
        person = new PersonObject(name, parent);
    }
};


#endif