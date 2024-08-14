#pragma once
#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
An Interface which would be implemented by 
- all the concrete subjects
- all the proxies to those concrete subjects
*/
class ISubject {
public:
    virtual ~ISubject() {}
    virtual void add(string book) = 0;
    virtual void remove(string book) = 0;
    virtual vector<string> list() = 0;
    virtual string getName() = 0;
};


// Concrete Subject
class LibrarySubject: public ISubject {
    string name;
    vector<string> books;
public:
    LibrarySubject(string name) {
        this->name = name;
    }
    virtual void add(string book) {
        this->books.push_back(book);
        printf("Library '%s': Added '%s'\n", this->name.c_str(), book.c_str());
    }
    virtual void remove(string book){
        int idx = 0;

        for (int i=0; i<this->books.size(); i++) {
            if (this->books[i] == book) {
                idx = i;
                break;
            }
        }

        this->books.erase(idx + this->books.begin());
        printf("Library '%s': Removed '%s'\n", this->name.c_str(), book.c_str());
    }
    virtual vector<string> list() {
        return this->books;
    }
    virtual string getName() {
        return this->name;
    }
};


#endif