# Interpreter Design Pattern

## Examples 

### Arithmatic Expression

#### Structure
```
├── abstract-expression
│   ├── abstract.h
│   ├── non-terminal-expression
│   │   └── non-terminal.h
│   └── terminal-expression
│       └── terminal.h
├── context
│   └── context.h
├── interpreter
│   └── interpreter.h
└── main.cpp
```
#### Components

Abstract Expression
A common interface to be followed and contains methods such as the interpret(). Interpret() takes in the context as input to produce a result.

Terminal Expression
Leaves in the expression tree.

Non-Terminal Expression
Composed of other non-terminal or terminal expressions. Forms a node in the expression tree with the left and right subtrees as other expressions

Context
A source of information for the interpret method to work with. Eg values of characters in an expression

Interpreter
Engages directly with the client, has-a context, builds the expression tree, and calls the interpret method

#### Flow
1. Client has a string based expression input or his grammar sentence
2. Client creates a context object and passes his information to the same
3. Client creates an interpreter object with the context object
4. Client uses the methods exposed by the interpreter object



## UML Example
![UML Interpreter](../../imgs/uml-interpreter.png)

## References
1. https://www.geeksforgeeks.org/interpreter-design-pattern/?ref=lbp
2. https://java-design-patterns.com/patterns/interpreter