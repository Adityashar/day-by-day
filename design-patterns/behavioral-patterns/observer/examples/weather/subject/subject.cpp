#include "subject.h"

using namespace std;


void StationSubject::setState(string newState) {
    this->state = newState;
    publish();
}

void StationSubject::subscribe(Observer *ob) {
    subscribers.push_back(ob);
    printf("Added '%s' to '%s'\n", ob->name.c_str(), this->name.c_str());
}


void StationSubject::unsubscribe(Observer *ob) {
    int idx = -1;
    for (int i=0; i<subscribers.size(); i++) {
        if (subscribers[i]->name == ob->name) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("No subscriber with name '%s' found in subject '%s'\n", ob->name.c_str(), this->name.c_str());
        return;
    }

    // NOT Last Element
    if (idx != subscribers.size()-1) {
        subscribers[idx] = subscribers[subscribers.size()-1];
    }
    subscribers.pop_back();
    printf("Removed '%s' from '%s'\n", ob->name.c_str(), this->name.c_str());
}

void StationSubject::publish() {
    printf("Publishing newState='%s' \n", this->state.c_str());

    for (auto &ob: this->subscribers) {
        printf("Published newState to Observer '%s'\n", ob->name.c_str());
        ob->update(this->state);
    }
}