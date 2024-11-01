#pragma once
#ifndef HELLO_H_

#include <iostream>
using namespace std;

class Hello {
    string input;
public:
    Hello(string s): input(s) { }
    string getInput() { return input; }
};


#endif