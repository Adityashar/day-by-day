#include<iostream>
#include<vector>
#include "subject/subject.h"

using namespace std;


int main() {

    printf("Initialising the Server / event handler system \n");

    // Set Subject as Weather Station Subject
    Subject *station(new StationSubject());

    // Add Observers to Subject
    Observer *local1 = new LocalObserver();
    Observer *local2 = new LocalObserver();
    Observer *print1 = new PrintObserver();

    station->subscribe(local1);
    station->subscribe(local2);
    station->subscribe(print1);

    station->setState("RAINY");

    station->unsubscribe(local2);

    station->setState("SUNNY");

    return 0;
}