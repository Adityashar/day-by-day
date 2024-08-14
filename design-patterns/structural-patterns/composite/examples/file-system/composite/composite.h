#pragma once
#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "../component/component.h"
#include <iostream>
#include <vector>
using namespace std;


/*
Concrete Composite Class
 * The Composite class represents the complex components that may have children.
 * Usually, the Composite objects delegate the actual work to their children and
 * then "sum-up" the result.
*/
class DirectoryComposite: public FileSystemComponent {
    vector<FileSystemComponent*> children;
    string directoryName;
public:
    DirectoryComposite(string name) {
        directoryName = name;
        printf("DirectoryComposite: Created: Name='%s' \n", name.c_str());
    }
    ~DirectoryComposite() {
        printf("DirectoryComposite: Destroyed: Name='%s' \n", directoryName.c_str());
    }

    // Composite Functions
    virtual bool isComposite() {
        return true;
    }
    virtual void add(FileSystemComponent *c) {
        printf("DirectoryComposite: Added: Type='%d' \n", c->isComposite());
        children.push_back(c);
    }
    virtual void remove(FileSystemComponent *c) {
        for (int i=0; i<children.size(); i++) {
            if (children[i] == c) {
                children.erase(children.begin() + i);
            }
        }
        printf("DirectoryComposite: Removed: Type='%d' \n", c->isComposite());
    }
    virtual FileSystemComponent* getChildren(int i) {
        return children[i];
    }
    // not virtual
    vector<FileSystemComponent*> getAllChildren() {
        return children;
    }

    // Common Methods
    virtual double work() {
        double total = 0;
        for (auto &i: children)
            total += i->work();
        return total;
    }

    virtual string tree() {
        string response = "(" + directoryName + ": ";
        for (auto &i: children)
            response += i->tree() + ", ";

        return response + ")";
    }
}; 

#endif