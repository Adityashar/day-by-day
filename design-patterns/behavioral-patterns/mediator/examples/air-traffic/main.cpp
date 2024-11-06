#include <iostream>
#include "colleague/colleague.h"

using namespace std;


int main() {

    Mediator *ATC = new AtcMediator();

    AirplaneColleague *ac1 = new AirbusColleague(ATC);
    AirplaneColleague *ac2 = new AirbusColleague(ATC);
    AirplaneColleague *ac3 = new BoeingColleague(ATC);

    ac1->notifyLanding();
    ac2->notifyTakeOff();

    return 0;
}