#pragma once
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>
#include <vector>
using namespace std;


/*
Component Interface
- Common interface for both the leaf and the composite
- Contains a set of common operations
*/
class FileSystemComponent {
public:
    // Constructor
    FileSystemComponent() {
        cout<<"FileSystemComponent: Created\n";
    }

    // Common Methods
    virtual string tree() = 0;
    virtual double work() = 0;

    // Composite
    virtual bool isComposite() = 0;
    virtual void add(FileSystemComponent *c) {}
    virtual void remove(FileSystemComponent *c) {}
    virtual FileSystemComponent* getChildren(int i) { return NULL; }
    // virtual vector<FileSystemComponent*> getAllChildren();

    // Destructor
    virtual ~FileSystemComponent() {
        cout<<"FileSystemComponent: Destroyed\n";
    }
};




#endif