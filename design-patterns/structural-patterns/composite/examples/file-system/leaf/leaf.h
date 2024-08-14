#pragma once
#ifndef LEAF_H_
#define LEAF_H_

#include "../component/component.h"
#include <iostream>
using namespace std;


/*
Concrete Leaf Class
- Implements the component interface
*/
class FileLeaf: public FileSystemComponent {
    string fileName;
    double fileSize;
public:
    FileLeaf(string fn, double fs) {
        fileName = fn;
        fileSize = fs;
        printf("FileLeaf: Created: Name='%s', Size='%fkb' \n", fn.c_str(), fs);
    }
    ~FileLeaf() {
        printf("FileLeaf: Destroyed: Name='%s', Size='%fkb' \n", fileName.c_str(), fileSize);
    }

    virtual double work() {
        return fileSize;
    }

    virtual bool isComposite() {
        return false;
    }

    virtual string tree() {
        return fileName;
    }
};



#endif