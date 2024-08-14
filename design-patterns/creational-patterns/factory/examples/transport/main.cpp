#include <iostream>
#include "creator/creator.h"

using namespace std;


void clientCode (Transport *tr) {
    tr->deliver();
}

int main() {

    printf("Client: Working with Truck Factory\n");
    TransportFactory *f1 = new TruckFactory();
    clientCode(f1->create());

    printf("Client: Working with Ship Factory\n");
    TransportFactory *f2 = new ShipFactory();
    clientCode(f2->create());


    delete f1;
    delete f2;

    return 0;
}