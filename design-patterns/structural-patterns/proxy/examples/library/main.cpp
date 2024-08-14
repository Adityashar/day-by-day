#include <iostream>
#include <vector>
#include "proxy/proxy.h"
#include "subject/subject.h"
using namespace std;

void clientCode(ISubject *sub) {
    sub->add("abcd");
    sub->remove("abcd");
    printf("Client: Library Name '%s'\n", sub->getName().c_str());
    
    vector<string> response = sub->list();
    if (response.size() > 0) {
        printf("Client: List: ");
        for (int i=0; i<response.size(); i++) {
            printf("%s, ", response[i].c_str());
        }
    }
    printf("\n");
}

int main() {

    ISubject *lib = new LibrarySubject("DTU");
    lib->add("some");
    lib->add("thing");
    lib->add("one more");

    ISubject *proxy = new LibraryProxy(lib, "user");
    clientCode(proxy);
  
    proxy = new LibraryProxy(lib, "admin");
    clientCode(proxy);

    delete proxy;

    return 0;
}