#pragma once
#ifndef WORKER_H_
#define WORKER_H_

#include <exception>
#include <iostream>

using namespace std;


class ThreadPoolWorkerException: public exception {
    string msg;
public:
    ThreadPoolWorkerException(string&& text) {
        msg = move(text);
    }
    
    const char* what() {
        return msg.c_str();
    }
};

#endif