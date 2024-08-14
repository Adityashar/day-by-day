#include <iostream>
#include "abstraction/abstraction.h"
#include "implementer/implementor.h"

using namespace std;


void clientCode (VehicleAbstraction *vehicle) {
    printf("Client Build\n");
    vehicle->build();
}


int main() {

    ProductionImplementor *PI = new CarProductionImplementor();
    AssemblyImplementor *AI = new CarAssemblyImplementor();

    VehicleAbstraction *vehicle = new CarAbstraction(PI, AI, "car-a");

    clientCode(vehicle);

    PI = new TruckProductionImplementor();
    AI = new TruckAssemblyImplementor();

    vehicle = new TruckAbstraction(PI, AI, "truck-a");

    clientCode(vehicle);

    delete vehicle;

    return 0;
}