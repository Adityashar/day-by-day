#include <iostream>
#include <vector>
#include "facade/facade.h"

using namespace std;

void clientCode(Facade *mine) {
    mine->workday();
}

int main() {

    Worker *w1 = new GoldWorker("g1");
    Worker *w2 = new GoldWorker("g2");
    Worker *w3 = new TunnelWorker("t1");

    Facade *mine = new MineFacade({w1, w2, w3});

    clientCode(mine);

    return 0;
}