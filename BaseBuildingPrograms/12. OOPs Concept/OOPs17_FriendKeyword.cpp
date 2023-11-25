// In C++, the 'friend' keyword is used to declare a class or a function as a friend of
// another class. When a function or a class is declared as a friend, it is granted access
// to the private and protected members of the class that declares it as a friend.

#include <iostream>
using namespace std;

class A {
    private:
        int x, y;
    public:
        void setData(int x, int y) {
            this->x = x;
            this->y = y;
        }

        friend class B;   // declaring class B as A's friend, i.e.
                         // all objects of class B can access A's non-public members
        friend void Sum(A &);   // declaring Sum() as A's friend, i.e.
                               // it can access A's non-public members 
};

class B {
    public:
        void showData(A &obj) {
            cout << "x = " << obj.x << "\n" << "y = " << obj.y << "\n";
        }
};

void Sum(A &obj) {
    cout << "x + y = " << obj.x + obj.y << "\n";
}

int main() {
    A obj1;
    obj1.setData(5, 4);

    B obj2;
    obj2.showData(obj1);

    Sum(obj1);

    return 0;
}