#pragma once
#ifndef COLLECTION_H_
#define COLLECTION_H_


#include <iostream>
#include <vector>
#include "../iterator/iterator.h"
using namespace std;


/*
Collection Interface
An aggregate object of some data structure
*/
class ICollection {
public:
    virtual ~ICollection() { }

    virtual IIterator* getIterator() = 0;
    virtual void add(string name, string parent) {}
};


// Concrete Collection
// Organisation Tree Collection
class OrganisationCollection: public ICollection {
    Node *organistionRoot; // Collection of Tree Structure

    Node* find(Node *root, string name) {
        if (root == NULL)
            return NULL;
        
        if (root->person->getName() == name)
            return root;
        
        for (int i=0; i<root->children.size(); i++) {
            Node *ret = find(root->children[i], name);
            if (ret != NULL) {
                return ret;
            }
        }
        return NULL;
    }
public:
    OrganisationCollection() {}

    // Add Node to Collection
    void add(string name, string parent) {
        if (organistionRoot == NULL) {
            organistionRoot = new Node(name, parent);
            return;
        }

        Node *parentNode = find(organistionRoot, parent);
        if (parentNode != NULL)
            parentNode->children.push_back(new Node(name, parent));
    }

    // Iterator
    virtual IIterator* getIterator() {
        return new DfsIterator(organistionRoot);
    }
};


#endif