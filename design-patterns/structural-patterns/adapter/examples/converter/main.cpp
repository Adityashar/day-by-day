#include <iostream>
#include "adaptee/adaptee.h"
#include "target/target.h"

using namespace std;


void clientCode(Target *adp) {
    string resp = adp->response("clientA");
    printf("Client: Response: '%s'\n", resp.c_str());
}

int main() {

    Adaptee *serv = new Adaptee();
    Target *adapter = new Adapter(serv);

    clientCode(adapter);
    
    delete adapter;
    delete serv;

    return 0;
}