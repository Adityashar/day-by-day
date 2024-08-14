#include<iostream>
#include<string>
using namespace std;


class Base {
public:
    int b;

    Base(int v) {
        b = v;
    }

    virtual void SayHello(string name) {
        cout<<"Heello "<<name<<" from Base Class!"<<endl;
        cout<<"b: "<<b<<endl;
    }

    void SayBye(string name) {
        cout<<"Byee "<<name<<" from Base Class!"<<endl;
    }
};


class DerivedA: public Base {
public:
    int da;

    DerivedA(int v1, int v2): Base(v2) {
        da = v1;
    }

    void SayHello(string name) {
        cout<<"Heello "<<name<<" from DerivedA Class!"<<endl;
        cout<<"b: "<<b<<" ; da: "<<da<<endl;
    }

    void SayBye(string name) {
        cout<<"Byee "<<name<<" from DerivedA Class!"<<endl;
    }
};


class DerivedB: public Base {
public:
    int db;

    DerivedB(int v1, int v2): Base(v2) {
        db = v1;
    }

    void SayHello(string name) {
        cout<<"Heello "<<name<<" from DerivedB Class!"<<endl;
        cout<<"b: "<<b<<" ; db: "<<db<<endl;
    }

    void SayBye(string name) {
        cout<<"Byee "<<name<<" from DerivedB Class!"<<endl;
    }
};


int main() {
    cout<<"This is an example for runtime polymorphism via Virtual Functions!"<<endl;

    Base *btr;
    
    DerivedA dA(1, 10);
    DerivedB dB(2, 10);

    string name = "Abcd";

    btr = &dA;

    btr->SayHello(name);
    btr->SayBye(name);

    btr = &dB;

    btr->SayHello(name);
    btr->SayBye(name);

    btr = new Base(11);

    btr->SayHello(name);
    btr->SayBye(name);
    
    return 0;
}