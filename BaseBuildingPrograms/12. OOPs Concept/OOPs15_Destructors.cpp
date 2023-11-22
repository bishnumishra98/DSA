// In C++, a destructor is a special member function of a class that is responsible for releasing
// resources or performing cleanup when an object of that class goes out of scope or is explicitly
// deleted. The destructor has the same name as the class, preceded by a tilde (~). It is called automatically when an object is destroyed, either at the end of its scope or when delete is explicitly called on a dynamically allocated object.

// Properties of constructors are:
// 1) Constructor is an instance member function of class. It can never be static.
// 2) The name of constructor must be the same as the class name.
// 3) It has no return type.
// 4) Constructors must be placed in public section of class.
// 5) If we do not specify a constructor, C++ compiler generates a default constructor for object
//    which expects no parameter and has an empty body. However, default constructor initializes
//    instance variables with garbage values. Thus, it is recommended to explicitly define a constructor.