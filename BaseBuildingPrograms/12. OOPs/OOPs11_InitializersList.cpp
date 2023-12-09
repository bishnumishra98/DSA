// The initializer list is a way to initialize class members when the object is created,
// and it is a feature of the constructor. The list of members to be initialized is indicated
// with the constructor as a comma-separated list followed by a colon.


// Q) Why initializer lists over regular constructors?

// A) Because constructors cannot directly initialize non-static const data members within the body
//    of the constructor. Instead, initializer lists are used for such initialization.

#include <iostream>
using namespace std;

class Dummy {
    private:
        const int a;   // non-static const data member
        int b;
        int c;
    public:
        // Dummy(int x, int c) {
        //     a = 5;   // constructor cannot initialize 'a' because 'a' is a 'const' data member.
        //     b = x;
        //     this->c = c;
        // }

        // Instead, we define a initializers list to initialize 'a':
        Dummy(int x, int c) : a(5), b(x), c(c) {}   // this pointer is not required in initializer list


        void showDummy() {
            cout << "a = " << a << "\n"
                 << "b = " << b << "\n"
                 << "c = " << c << "\n\n";
        }
};

int main() {
    Dummy d1(6, 7);
    d1.showDummy();

    return 0;
}