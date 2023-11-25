// When an operator is overloaded with multiple meanings, it is called Operator overloading.
// It is a way to implement compile time polymorphism. Symbols like +, -, /, *, %, etc cannot
// be directly used as function names. Instead, the operator keyword is used before them to
// define operator overload functions. Except for '.', '::', 'sizeof', and '?:', most valid
// C operators can be overloaded in C++.


#include <iostream>
using namespace std;

class Complex {
    private:
        int x, y;
    public:
        void setData(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void showData() const {
            cout << "x=" << x << ", y=" << y << "\n";
        }

        // Giving '+' operator another meaning. Now '+' operator can also add two complex numbers.
        // This is a operator overload fuction.
        Complex operator + (const Complex &c) {
            Complex sum;
            sum.x = x + c.x;
            sum.y = y + c.y;
            return sum;
        }

        // pre-increment operator overload
        Complex operator ++ () {
            Complex ans;
            ans.x = ++x;
            ans.y = ++y;
            return ans; 
        }

        // post-increment operator overload
        // The 'int' parameter in the function signature is a dummy parameter
        // used to differentiate between pre-increment and post-increment overloads.
        Complex operator ++ (int) {
            Complex ans;
            ans.x = x++;
            ans.y = y++;
            return ans; 
        }

};

int main() {
    Complex c1, c2, c3, c4, c5;
    c1.setData(3, 4);
    c2.setData(7, 9);
    c3 = c2 + c1;   // or, c3 = c2.operator + (c1);
    c3.showData();   // x=10, y=13

    c4 = ++c1;   // or, c4 = c1.operator ++();
    c1.showData();   // x=4, y=5
    c4.showData();   // x=4, y=5

    c5 = c2++;   // or, c5 = c2.operator ++(0);   // not only (0), we can pass any dummy int value
    c2.showData();   // x=8, y=10
    c5.showData();   // x=7, y=9

    return 0;
}