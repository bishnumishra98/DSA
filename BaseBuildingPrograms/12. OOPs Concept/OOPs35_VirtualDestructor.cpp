// Module: Virtual destructor

// Q) Are virtual constructors possible ?
// Answer: No
// Explanation: Constructors are not inherited, and they are not called through pointers or
//              references. When you create an object of a derived class, the constructor of
//              the base class is automatically called before the derived class constructor.
//              This is part of the normal process of constructing an object.
//              If you need polymorphic behavior during object creation, you typically rely on
//              virtual functions, which are called after the object has been fully constructed.
//              Constructors themselves are not virtual because they are responsible for
//              initializing the object's state, and it would be problematic to have virtual
//              dispatch during this initialization process.

// Q) Are virtual destructors possible ?
// Answer: Yes
// Explanation: A virtual destructor is useful when you have a base class with virtual functions,
//              and you want to ensure that the correct destructor is called for objects of
//              derived classes when they are deleted through a pointer to the base class.
