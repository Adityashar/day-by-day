#include <iostream>
#include "forest.h"

using namespace std;



int main() {

    FlyweightFactory *factory = new TreeTypeFactory();
    Forest *forest = new Forest(factory);

    forest->addTree(0, 0, "red", "evergreen", "abc");
    forest->addTree(1, 0, "blue", "evergreen", "abc");
    forest->addTree(2, 0, "red", "evergreen", "abc");
    forest->addTree(3, 0, "red", "evergreen", "abc");
    forest->addTree(0, 1, "blue", "coniferous", "tgf");
    forest->addTree(0, 2, "blue", "evergreen", "tgf");
    forest->addTree(0, 3, "blue", "coniferous", "tgf");

    forest->draw();

    delete forest;

    return 0;
}