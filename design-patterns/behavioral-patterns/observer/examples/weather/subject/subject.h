#pragma once
#ifndef SUBJECT_H_
#define SUBJECT_H_

#include<vector>
#include "../observer/observer.h"

using namespace std;


// Subject Interface
class Subject {
public:
    vector<Observer*> subscribers;
    string state;
    string name;

    virtual void setState(string newState) = 0;
    virtual void subscribe(Observer *ob) = 0;
    virtual void unsubscribe(Observer *ob) = 0;
    virtual void publish() = 0;
};



// Concrete Subject
class StationSubject: public Subject {
public:
    StationSubject() {
        this->name = "WEATHER_STATION";
        this->state = "NOT_UPDATED";
    }

    void setState(string newState);
    void subscribe(Observer *ob);
    void unsubscribe(Observer *ob);
    void publish();
};



#endif