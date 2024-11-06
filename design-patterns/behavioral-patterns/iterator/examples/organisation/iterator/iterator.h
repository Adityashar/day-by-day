#pragma once
#ifndef ITERATOR_H_
#define ITERATOR_H_


#include <iostream>
#include <stack>
#include "../object/object.h"
using namespace std;


/*
Iterator Interface
*/
class IIterator {
public:
    virtual bool hasNext() = 0;
    virtual PersonObject* next() = 0;

    virtual ~IIterator() {}
};


// A DFS Iterator
class DfsIterator: public IIterator {
    Node *root;

    stack<Node*> cache;
public:
    DfsIterator(Node *input) {
        root = input;
        cache.push(root);
    }

    void reset() {
        while (!cache.empty())
            cache.pop();
        
        cache.push(root);
    }

    // Interface Methods
    virtual bool hasNext() {
        return cache.size() > 0;
    }

    virtual PersonObject* next() {
        if (!hasNext())
            return NULL;
        
        Node *top = cache.top(); cache.pop();
        
        // Push children to cache in reverse order
        for (int i=top->children.size()-1; i>=0; i--)
            cache.push(top->children[i]);
        
        return top->person;
    }
};

#endif