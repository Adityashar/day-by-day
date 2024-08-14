#include <iostream>
#include <mutex>
using namespace std;

mutex mut;

/*
Singleton Class
- Private Constructor
- Static objects of its own
- Static Member Function 
*/
class Singleton {
    static Singleton *obj;
    string value;

    Singleton(string val) {
        value = val;
    };
public:
    static Singleton* getObject(string value) {
        if (obj == NULL) {
            mut.lock();
            obj = new Singleton(value);
            mut.unlock();
        }
        return obj;
    }

    string getValue() {
        return value;
    }
};


// Important declaration of Static Object
Singleton* Singleton::obj = nullptr;

int main() {

    Singleton *obj = Singleton::getObject("first");
    cout<<obj->getValue()<<endl;

    obj = Singleton::getObject("second");
    cout<<obj->getValue()<<endl;

    return 0;
}