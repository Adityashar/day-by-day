#include <iostream>
#include "component/component.h"
#include "decorators/decorator.h"

using namespace std;



int main() {

    printf("Client: Initialising the pattern example\n");

    // Make a concrete component object of the component interface
    // using the FileComponent class
    IComponent *concreteFile = new FileComponent("hello.txt");

    // Write Data
    // and Read the same data
    concreteFile->write("hello world !!");
    printf("Client: FileData = '%s'\n", concreteFile->read().c_str());

    printf("\n");
    // Decorate concreteFile with Encryption Decorator
    concreteFile = new EncryptionDecorator(concreteFile);

    // Write Data
    // and Read the same data
    concreteFile->write("hello world but encrypted !!");
    printf("Client: FileData = '%s'\n", concreteFile->read().c_str());

    printf("\n");

    // With All three Decorators
    IComponent *decoratedFile = new FileComponent("decorated_hello.txt");

    decoratedFile = new IDecorator(decoratedFile);
    decoratedFile = new EncryptionDecorator(decoratedFile);
    decoratedFile = new CompressionDecorator(decoratedFile);

    // Write Data
    // and Read the same data
    decoratedFile->write("hello from decorated!!");
    printf("Client: FileData = '%s'\n", decoratedFile->read().c_str());

    printf("\n");

    printf("Client: Hierarchy: %s", decoratedFile->getName().c_str());

    delete concreteFile;
    delete decoratedFile;

    return 0;
}



/*

In this example, 
the Decorator pattern lets you compress and encrypt sensitive data independently 
from the code that actually uses this data.

*/