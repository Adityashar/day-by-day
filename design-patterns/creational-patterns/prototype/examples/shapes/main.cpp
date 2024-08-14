#include <iostream>
#include "prototypes/prototypes.h"

using namespace std;


void clientCode(Shape *prototype) {
    printf("Client: Shape: Color: '%s'\n", prototype->getColor().c_str());

    Shape *clone = prototype->clone();

    printf("Client: Clone Shape: Color: '%s'\n", prototype->getColor().c_str());    
}

int main() {

    Shape *sh = new Circle(3, "red");
    clientCode(sh);

    return 0;
}