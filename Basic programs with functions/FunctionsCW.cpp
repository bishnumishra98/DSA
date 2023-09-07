#include <iostream>
#include <cmath>
using namespace std;

// max of three numbers
int maxOfThree(float a, float b, float c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

// counting from 1 to n
void printNumbers(int n) {
    cout << "The sequence is: " << endl;
    for(int i=1; i<=n; i++) {
        cout << i << endl;
    }
}

// checking Odd or Even number
bool checkEven(int n) {
    // // Technique 1
    // return n % 2 == 0;

    // Technique 2
    return (n & 1) == 0;
}

// checking Prime or Composite number
bool checkPrime(int n) {
    if(n<=1) {
        return false;
    }

    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    
    return true;
}

// Sum of all numbers from 1 to n
int sumOfNumbers(int n) {
    // int sum = 0;
    // for(int i=1; i<=n; i++) {
    //     sum += i;
    // }
    // return sum;

    // Note that formula for sum of numbers is the best code for it.
    return (n * (n + 1)) / 2;
}

// Sum of all even numbers from 1 to n
int sumOfEvenNumbers(int n) {
    // int sum = 0;
    // for(int i=2; i<=n; i=i+2) {
    //     sum += i;
    // }
    // return sum;

    // Note that formula for sum of even numbers is the best code for it.
    // Note that if (n/2) is a decimal number, don't worry; we want the integer part only for this formula.
    return ((n / 2) + 1) * (n / 2);
}


int main() {
    // // max of three numbers
    // float n1, n2, n3;
    // cin >> n1 >> n2 >> n3;
    // cout << "The largest number is: " << maxOfThree(n1, n2, n3);


    // // counting from 1 to n
    // int n;
    // cin >> n;
    // printNumbers(n);


    // // checking Odd or Even number
    // int n;
    // cin >> n;
    // if(checkEven(n)) {
    //     cout << "Even number";
    // } else {
    //     cout << "Odd number";
    // }


    // // checking Prime or Composite number
    // int n;
    // cin >> n;
    // if(checkPrime(n)) {
    //     cout << "Prime number";
    // } else {
    //     cout << "Composite number";
    // }


    // // Sum of all numbers from 1 to n
    // int n;
    // cin >> n;
    // cout << "Sum of numbers: " << sumOfNumbers(n);


    // Sum of all even numbers from 1 to n
    int n;
    cin >> n;
    cout << "Sum of numbers: " << sumOfEvenNumbers(n);

    return 0;
}