// The initializer list is a way to initialize class members when the object is created,
// and it is a feature of the constructor. The list of members to be initialized is indicated
// with the constructor as a comma-separated list followed by a colon.

// Why initializer lists over regular constructors?
// Because constructors cannot directly initialize non-static const data members within the body
// of the constructor. Instead, initializer lists are used for such initialization.

#include <iostream>
using namespace std;

class Dummy {
    private:
        const int a;   // non-static const data member
        int b;
    public:
        // Dummy(int x) {
        //     a = 0;   // constructor cannot initialize 'a' because 'a' is a 'const' data member.
        //     b = x;
        // }

        // Instead, we define a initializers list to initialize 'a':
        Dummy(int x) : a(0), b(x) {}


        void showDummy() {
            cout << "a = " << a << "\n"
                 << "b = " << b << "\n\n";
        }

};

int main() {
    Dummy d1(6);
    d1.showDummy();

    return 0;
}