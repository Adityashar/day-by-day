#include <iostream>
#include "interpreter/interpreter.h"
#include "context/context.h"

using namespace std;



int main() {

    Context *con = new Context();
    con->setValue("a", 10);
    con->setValue("c", 5);
    con->setValue("b", 2);

    string exp = "abc+*";
    Interpretor *pret = new Interpretor(con);

    cout<<"Building Expression: "<<exp<<endl;
    pret->buildExpression(exp);

    cout<<"Printing Expression: "<<pret->displayExpression()<<endl;
    cout<<"Evaluating Expression: "<<pret->interpretExpression()<<endl;

    return 0;
}


/*

> g++ -std=c++17 -o ~/dump/build main.cpp; ~/dump/build
Building Expression: ab+c*
Printing Expression: c*b+a
Evaluating Expression: 60
> g++ -std=c++17 -o ~/dump/build main.cpp; ~/dump/build
Building Expression: abc+*
Printing Expression: c+b*a
Evaluating Expression: 70

*/