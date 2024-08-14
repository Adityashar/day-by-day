#include <iostream>
#include "beverages.h"
using namespace std;



int main () {

    BeverageMaker *makeCoffee = new CoffeeMaker("mycafe");
    makeCoffee->makeBeverage();

    BeverageMaker *makeTea = new TeaMaker("mytea");
    makeTea->makeBeverage();

    return 0;
}