#include <iostream>
#include <list>
#include <queue>
#include "caretaker/caretaker.h"
using namespace std;


int main() {
    DocumentOriginator *orig = new DocumentOriginator("this is init state");
    Caretaker *ct = new Caretaker(orig);

    ct->saveState();
    
    orig->doWork("this is next state");
    orig->doWork("this is next next state");

    ct->saveState();

    orig->doWork("this is next next next state");
    
    ct->saveState();
    ct->restore();
    ct->restore();

    return 0;
}