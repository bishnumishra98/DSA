// There are 3 types static members in C++:
// 1) static local/global variables
// 2) static member variables
// 3) static member functions

// Properties of static member variables:

// 1) By default initialized to 0, and scope throughout the program.

// 2) Declared inside class body, and defined outside body of class, because static member
//    variables are shared by all instances of a class, so they need to be initialized only
//    once. If they were defined inside the class body, they would be initialized every time
//    a new instance of the class is created.

// 3) They do not belong to any object unlike other instance members of class, i.e. they can
//    be used by any object. They are also called class variables.

// 4) There is only one copy of the variable for the entire class. Therefore, changing the value
//    of 'weight' for one instance (e.g., for Jeet) will affect all instances of the class.

// Below is the illustration for static member variables:

#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int age;

        // declaring static member variable or class variable
        static float weight;

    public:
        void setName(string str) {
            name = str;
        }

        void setAge(int age) {
            this->age = age;
        }

        void showStudentInfo() {
            cout << "Name: " << name << "\n"
                 << "Age: " << age << "\n"
                 << "Weight: " << weight << "\n\n";
        }
};

// defining static member variable
// Syntax: data-type class_name scopeResolutionOperator variable_name = value;
float Student:: weight = 75;   // Note: 'float Student:: weight;' would mean 'weight' initialized to 0.

int main() {
    Student s1, s2;
    s1.setName("Vishnu");
    s1.setAge(25);
    s1.showStudentInfo();

    s2.setName("Jeet");
    s2.setAge(24);
    s2.showStudentInfo();


    return 0;
}

// Note: Value of static variable or class variable can be changed via both static and non-static
// function. In next class, we will see how to manipulate static variable via a static function.