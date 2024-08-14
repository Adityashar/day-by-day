# Bridge Design Patter


## Examples

### Workshop

#### Structure
```
├── abstraction
│   └── abstraction.h
├── implementer
│   ├── assembly
│   │   └── implementor.h
│   ├── implementor.h
│   └── production
│       └── implementor.h
└── main.cpp
```

#### Components
##### Abstaction
- High level control layer for the vehicles workshop
- Declares some virtual methods
- Client uses the abstraction directly - hides the implementation details

##### Refined Abstraction
- Implements the 'abstraction' interface
- Holds an object for all of the implementer interfaces (aggregation)
- calls the implementer logic using the above objects

##### Implementer
- a common interface for specific functionalities' multiple implementations
- represents some redundant coding logic in the abstraction classes 

##### Conrete Implementer
- a concrete class extending the implementer interface

#### Flow
1. Driver creates an object of the Production and Assembly implementers
2. Driver creates an object of the Abstraction using the above implementers
3. Client uses the abstraction object to call the methods available in abstraction
4. Abstraction objects uses the implementer objects to call the implementer methods


#### UML Example
![UML Bridge](../../imgs/uml-bridge.png)


## References
1. https://www.geeksforgeeks.org/bridge-design-pattern/?ref=lbp
2. https://refactoring.guru/design-patterns/bridge