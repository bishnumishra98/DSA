// In C++, a private constructor is possible. Declaring a constructor as private means that the
// constructor can only be accessed or called within the class itself, and it cannot be accessed
// from outside the class or by other classes. This can be useful in various design patterns, such
// as the Singleton pattern, where you want to ensure that only one instance of a class is created,
// or in cases when we want an object to be made only from a class's friend class.

#include <iostream>
using namespace std;

// Constructor of Box class is made private. Thus, no objects of Box class can be made directly.
// To make objects of Box class, the programmer must use its friend class BoxFactory. One use case
// for this is to keep a count of the number of boxes made from the Box class.

class Box {
    private:
        int width;

        // ctor
        Box(int w) {
            width = w;
        }
    public:
        int getWidth() const {
            return width;
        }

        void setWidth(int w) {
            width = w;
        }

        friend class BoxFactory;
};

class BoxFactory {
    private:
        int count = 0;
    public:
        Box getABox(int w) {
            count++;
            return Box(w);
        }

        int getCount() {
            return count;
        }
};


int main() {
    BoxFactory bfact;

    Box b = bfact.getABox(5);
    cout << "Width of box1: " << b.getWidth() << "cm" << endl;

    Box c = bfact.getABox(6);
    cout << "Width of box2: " << c.getWidth() << "cm" << endl;

    Box d = bfact.getABox(7);
    cout << "Width of box3: " << d.getWidth() << "cm" << endl;

    cout << "Total boxes made: " << bfact.getCount() << endl;

    return 0;
}