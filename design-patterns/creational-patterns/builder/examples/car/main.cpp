#include "director/director.h"
#include <iostream>

using namespace std;


int main() {

    CarBuilder *cb = new ConcreteCarBuilder();
    CarBuilderDirector *cbd = new CarBuilderDirector(cb);

    // Build Sedan
    cbd->buildSedan(4, 1000, 4, "alloy", "red", "fwd");

    Car *sedan = cb->getObject();
    printf("Sedan: ");
    sedan->display();

    delete sedan;

    // Build SUV

    // Reset sedan
    cb->reset();

    cbd->buildSUV(4, 3000, 4, "alloy", "black", "awd");

    Car *suv = cb->getObject();
    printf("SUV: ");
    suv->display();

    delete cbd;

    return 0;
}