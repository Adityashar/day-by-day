#include <iostream>
#include <vector>
#include "composite/composite.h"
#include "leaf/leaf.h"

using namespace std;


void clientCode(FileSystemComponent *c) {
    cout<<"Total FileSystem Size: "<<c->work()<<endl;
    cout<<"FileSystem Tree: "<<c->tree()<<endl;
}


int main() {

    FileSystemComponent *simple = new FileLeaf("helo.txt", 2.3);
    clientCode(simple);
    delete simple;

    cout<<"-----------------------\n";

    FileSystemComponent *basic = new DirectoryComposite("d1");
    FileSystemComponent *child1 = new FileLeaf("helo.txt", 2.5);
    FileSystemComponent *child2 = new FileLeaf("wrld.h", 24.5);

    basic->add(child1);
    basic->add(child2);

    clientCode(basic);

    cout<<"-----------------------\n";

    FileSystemComponent *complex = new DirectoryComposite("home");
    FileSystemComponent *leaf1 = new FileLeaf("some.txt", 12.5);
    
    complex->add(leaf1);

    ///

    FileSystemComponent *branch1 = new DirectoryComposite("branch1");
    FileSystemComponent *leaf2 = new FileLeaf("abc.h", 14.5);

    branch1->add(leaf2);
    complex->add(branch1);

    ///

    FileSystemComponent *branch2 = new DirectoryComposite("branch2");
    FileSystemComponent *leaf3 = new FileLeaf("def.h", 10.5);
    FileSystemComponent *leaf4 = new FileLeaf("efg.h", 8.5);

    branch2->add(leaf3);
    branch2->add(leaf4);
    branch2->add(basic);
    complex->add(branch2);

    ///

    clientCode(complex);

    complex->remove(leaf1);

    cout<<"-----------------------\n";

    clientCode(complex);

    return 0;
}