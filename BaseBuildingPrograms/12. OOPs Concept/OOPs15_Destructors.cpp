// In C++, a destructor is a special member function of a class that is responsible for releasing
// resources or performing cleanup when an object of that class goes out of scope or is explicitly
// deleted.

// Properties of destructors are:
// 1) Destructor is an instance member function of class. It can never be static or const.
// 2) The name of destructor must be the same as the class name preceded by a tilde (~).
// 3) There can be only 1 destructor in a class and it must be placed in public section of class..
// 4) It has no return type or parameters.
// 5) Destructors are called in the reverse order of the constructors. For example, if objects
//    of classes A, B, and C are created, their destructors are called in the order C, B, A.
// 6) If we do not specify a destructor, C++ compiler generates a default destructor that is called
//    automatically(by main function), when an object goes out of scope or when delete is used to
//    deallocate memory for a dynamically allocated object.


// Q) Why to create a destructor if compiler creates default one on its own ?

// A) The compiler does automatically generate a default destructor if one is not explicitly defined.
//    However, there are cases where a programmer might want to provide their own destructor:

//    1) Custom Cleanup Logic:
//       If there is additional cleanup logic required beyond what the default destructor provides,
//       a programmer can define a custom destructor to ensure proper cleanup.

//    2) Order of Cleanup:
//       The order in which destructors are called matters, especially in complex systems with
//       multiple objects. If there is a specific order in which resources need to be released,
//       a programmer can control this order by providing a custom destructor.
