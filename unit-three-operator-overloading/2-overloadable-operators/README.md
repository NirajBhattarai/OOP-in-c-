# Overloadable Operators

In C++, most operators can be overloaded, including arithmetic (+, -, *, /), comparison (==, !=, <, >), assignment (=, +=, -=), and more. However, some operators such as ::, .*, ., and ?: cannot be overloaded. Overloading allows these operators to work with user-defined types, providing custom behavior. 

## Program Explanation

This program demonstrates which operators can be overloaded in C++ using a `Demo` class:

- The `Demo` class has a private integer member `value` and a constructor.
- The operators `+`, `-`, `*`, `==`, and `=` are overloaded to work with `Demo` objects.
- Each operator performs the corresponding operation on the `value` members of two `Demo` objects.
- In `main()`, two `Demo` objects are created. The overloaded operators are used to add, multiply, and compare them, and the results are printed. 