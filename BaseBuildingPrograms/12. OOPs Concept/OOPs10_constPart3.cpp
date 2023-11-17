// const keyword in C++ is used to declare constants and to specify that an identifier's value
// cannot be modified throughout its scope.

// In this module, we will see const with objects.

#include <iostream>
using namespace std;

class Student {
    private:
        int standard;
        mutable int roll_no;
        int age;
        float *weight;
    public:
        Student(int roll, int _age, float _weight) {
            standard = 12;
            roll_no = roll;
            age = _age;
            weight = new float(_weight);
        }

        int getStandard() const {
            // standard -= 1;   // 'standard' cannot be changed because getStandard() is declared 'const'
            return standard;
        }

        int getRoll() const {
            roll_no += 1;   // 'roll_no' can be changed because although getRoll() is declared 'const'
                           // but 'roll_no' is a mutable variable.
            return roll_no;
        }

        int getAge() {
            return age;
        }

        float getWeight() {
            return *weight;
        }
};

void printStudentInfo(Student &s) {
    cout << "Standard: " << s.getStandard() << "\n"
         << "Roll no: " << s.getRoll() << "\n"
         << "Age: " << s.getAge() << "\n"
         << "Weight: " << s.getWeight() << "\n\n";;
}

int main() {
    Student s1(1, 18, 65);
    printStudentInfo(s1);

    Student s2(2, 17, 60);
    printStudentInfo(s2);

    return 0;
}