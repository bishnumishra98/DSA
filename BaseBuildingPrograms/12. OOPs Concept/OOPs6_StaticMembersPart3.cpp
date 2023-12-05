// There are 3 types static members in C++:
// 1) static local/global variables
// 2) static member variables
// 3) static member functions

// Properties of static member function:

// 1) Declared inside class body, and can or cannot be defined outside the class.

// 2) Can be invoked with or without an object

// 3) Static functions can access only static members(e.g., weight) of class.

// Below is the illustration for static member function:

#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int age;

        static float weight;

    public:
        void setName(string str) {
            name = str;
        }

        void setAge(int age) {
            this->age = age;
        }

        // static member function
        static void setWeight(float w) {
            weight = w;
        }

        void showStudentInfo() {
            cout << "Name: " << name << "\n"
                 << "Age: " << age << "\n"
                 << "Weight: " << weight << "\n\n";
        }
};

float Student:: weight = 75;


int main() {
    Student s1, s2, s3, s4;
    s1.setName("Vishnu");
    s1.setAge(25);
    s1.showStudentInfo();

    s2.setName("Jeet");
    s2.setAge(24);
    s2.setWeight(65);   // invoking static function with an object
    s2.showStudentInfo();

    s3.setName("Sapil");
    s3.setAge(24);
    Student:: setWeight(80);   // invoking static function without an object
    s3.showStudentInfo();

    s4.setName("Kachra");
    s4.setAge(25);
    s4.showStudentInfo();

    return 0;
}