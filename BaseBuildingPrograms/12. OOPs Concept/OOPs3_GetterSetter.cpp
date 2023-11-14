#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    // private variables of a class can only be accessed via public methods
    public:
        // Getter methods (getName and getAge) return the values of private member variables name and age.
        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        // Setter methods (setName and setAge) allow us to set the values of the private member variables.
        void setName(string str) {
            name = str;
        }

        void setAge(int age) {
            this->age = age;   // this is a keyword & local object pointer that refers to the current
            // instance of the class. When formal argument have same name as instance member(age),
            // this pointer is used to differentiate them and tell that 'this->age' present on L.H.S
            // is the instance member variable.
        }
};

int main() {
    Student s1, s2;
    s1.setName("Vishnu");
    s1.setAge(25);

    s2.setName("Jeet");
    s2.setAge(24);

    cout << s1.getName() << " " << s1.getAge();
    cout << endl;
    cout << s2.getName() << " " << s2.getAge();

    return 0;
}