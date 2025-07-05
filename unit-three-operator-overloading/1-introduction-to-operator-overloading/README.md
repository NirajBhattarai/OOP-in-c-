# Introduction to Operator Overloading

Operator overloading in C++ allows developers to redefine the way operators work for user-defined types (classes and structs). This enables objects to be manipulated using familiar operators, making code more intuitive and readable. Overloading operators enhances the expressiveness of C++ and supports custom behaviors for arithmetic, comparison, and other operations. 

## Program Explanation

This program demonstrates basic operator overloading in C++ using a simple `Number` class:

- The `Number` class has a private integer member `value` and a constructor to initialize it.
- The `operator+` is overloaded to allow adding two `Number` objects using the `+` operator. It returns a new `Number` object whose value is the sum of the two operands.
- The `getValue()` method returns the stored value.
- In `main()`, two `Number` objects are created and added using the overloaded `+` operator. The result is printed to the console. 