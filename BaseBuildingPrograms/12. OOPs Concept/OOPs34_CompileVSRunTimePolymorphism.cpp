// Compile-time polymorphism and runtime polymorphism are two different types of polymorphism
// in C++ that occur at different stages of program execution.


// 1. Compile-time Polymorphism (Static Polymorphism):
// -> Binding Time: Occurs at compile-time.
// -> Method of Implementation: Achieved through function overloading and operator overloading.
// -> Resolution Time: Decided at compile-time based on the number and types of arguments passed
//                     to the function or operators used.
// -> Example: Function overloading, operator overloading, templates.
// -> Code example of Compile-time Polymorphism (Function Overloading):
        class Math {
        public:
            int Customadd(int a, int b) {
                return a + b;
            }

            double Customadd(double a, double b) {
                return a + b;
            }
        };
        // In the above example, the compiler determines which add function to call based
        // on the argument types during compilation.


// 2. Runtime Polymorphism (Dynamic Polymorphism):
// -> Binding Time: Occurs at runtime.
// -> Method of Implementation: Achieved through function overriding using virtual functions
//    and pointers/references.
// -> Resolution Time: Decided at runtime based on the actual type of the object.
// -> Example: Virtual functions, inheritance, interfaces.
// -> Code example of Runtime Polymorphism (Virtual Functions):
        class Shape {
        public:
            virtual int Customadd(int a, int b) {
                return a + b;
            }
        };

        class Circle : public Shape {
        public:
            int Customadd(int a, int b) {
                return a + b + 10;
            }
        };
