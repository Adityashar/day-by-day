# Virtual Functions

Member functions of a class which are defined or declared with the keyword `virtual`. Virtual functions implement runtime polymorphism in C++. To understand this, consider the following example:

- We have a parent class `Base` with a member function `void SayHello(string name)`
- Another class `Derived` inherits this aformentioned class and has a function with the same prototype

In this scenario, a pointer to the base class's object (`Base *btr`) can be used to access:

- base class's `SayHello` member function (`btr->SayHello("Base")`)
- child class's `SayHello` member function on referencing a child class object (`Derived do; btr = &do; btr->SayHello("Derived")`)

### Meaning
Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call. This is made possible through the runtime or late binding behavior.

### Rules when using Virtual Functions

- Virtual functions cannot be static.
- A virtual function can be a friend function of another class.
- Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
- The prototype of virtual functions should be the same in the base as well as the derived class.
- They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
- A class may have a virtual destructor but it cannot have a virtual constructor.


### Late and Early Binding
Late binding (Runtime) is done in accordance with the content of the pointer (i.e. location pointed to by pointer) and Early binding (Compile-time) is done according to the type of pointer since the print() function is declared with the virtual keyword so it will be bound at runtime (output is print derived class as the pointer is pointing to object of derived class) and show() is non-virtual so it will be bound during compile time (output is show base class as the pointer is of base type).


## Pure Virtual Functions
A virtual function is said to be `pure` if and only if it is declared as per the following:
```cpp
virtual void SayHello() = 0; 
```
If a pure virtual function is present in a class, then the class is also called as an Abstract Class (and no objects can be created for them).