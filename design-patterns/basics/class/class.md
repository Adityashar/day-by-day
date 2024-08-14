# Class

## Abstract Class
A class which contains atleast one `pure virtual function`, i.e., a function with just the declaration and no implementation.

- An abstract class cannot have an object
- A child class which inherits from an abstract class and does not implement / overrides all of the pure virtual functions, becomes an abstract class itself
- Pointers and References can be created to the Abstract class

```cpp
// An abstract class with constructor
class Base {
protected:
    // protected member variable
    int x;
 
public:
    // pure virtual function
    virtual void fun() = 0;
 
    // constructor of Base class
    Base(int i)
    {
        x = i;
        cout << "Constructor of base called\n";
    }
};
 
// Concrete Class
class Derived : public Base {
    // private member variable
    int y;
 
public:
    // calling the constructor of Base class
    Derived(int i, int j)
        : Base(i)
    {
        y = j;
    }
 
    // implementation of pure virtual function
    void fun()
    {
        cout << "x = " << x << ", y = " << y << '\n';
    }
};
 
int main(void)
{
    // creating an object of Derived class
    Derived d(4, 5);
 
    // calling the fun() function of Derived class
    d.fun();
 
    // creating an object of Derived class using
    // a pointer of the Base class
    Base* ptr = new Derived(6, 7);
 
    // calling the fun() function using the
    // pointer
    ptr->fun();
 
    return 0;
}
```

## Interface
An interface does not have an implementation of any of its methods, it can be considered as a collection of method declarations. In C++, an interface can be simulated by making all methods pure virtual. In Java, there is a separate keyword for the interface.

We can think of Interface as header files in C++, like in header files we only provide the body of the class that is going to implement it. Similarly in Java in Interface we only provide the body of the class and we write the actual code in whatever class implements it.

### Importance of Interfaces
- Any class derived from the pure abstract class (Interface) must implement all of the methods of the base class i.e. Interface.
- Interface pointers can be passed to functions and classes thereby we can call the functions of the derived class from there itself.

## Enum
Enums or Enumerated type (enumeration) is a user-defined data type that can be assigned some limited values. These values are defined by the programmer at the time of declaring the enumerated type.

```cpp
enum roll_no {
    satya = 70,
    aakanskah = 73,
    sanket = 31,
    aniket = 05,
    avinash = 68,
    shreya = 47,
    nikita = 69,
};
int main()
{
    enum roll_no obj;
    obj = avinash;
    cout << "The roll no  of avinash=" << obj;
}
```

### Enum Class
C++11 has introduced enum classes (also called scoped enumerations), that makes enumerations both strongly typed and strongly scoped. Class enum doesn’t allow implicit conversion to int, and also doesn’t compare enumerators from different enumerations.

```cpp
// Declaration
enum class Color{ Red, Green, Blue};

// Initialisation
Color col = Color::Red;
```