#include <iostream>
using namespace std;
//  1) When we pass an array to a function, they are passed by reference and only the base address 
//     of the array is passed to the function. Thus, we can even write void solve(int* arr, int size).
        // void solve(int arr[], int size) {
        //     cout << "Size of array inside solve = " << sizeof(arr) << endl;   // o/p: 8, size of pointer
        // }

        // int main() {
        //     int arr[] = {10, 20, 30, 40, 50};
        //     cout << "Size of array inside main = " << sizeof(arr) << endl;   // o/p: 20, (sizeof(int)*5)
        //     solve(arr, 5);

        //     return 0;
        // }

//  2) Predict the output - level 1:
        // void solve(int *brr, int size) {
        //     cout << "Inside solve, brr = " << brr << endl;   // o/p: 204, prints value of 'arr' as 'brr' stores value of 'arr', i.e. value of base address of 'arr'
        //     cout << "Inside solve, &brr = " << &brr << endl;   // o/p: 408 (suppose), pirnts address of 'brr'
        // }

        // int main() {
        //     int arr[] = {10, 20, 30, 40, 50};
        //     cout << "Inside main, arr = " << arr << endl;   // o/p: 204 (suppose), prints base address of 'arr'
        //     cout << "Inside main, &arr = " << &arr << endl;   // o/p: 204, prints base address of 'arr'
        //     solve(arr, 5);

        //     return 0;
        // }

//  3) Predict the output - level 2:
        // void solve(int *arr, int size) {
        //     *arr = *arr + 1;
        // }

        // int main() {
        //     int arr[] = {10, 20, 30, 40, 50};
        //     solve(arr, 5);
        //     for(auto element: arr) {
        //         cout << element << " ";   // prints 11 20 30 40 50, because 'arr' variable in solve()
        //         // stores base address of 'arr'. Thus, '*arr' means value at base address, i.e. 10.
        //         // Then, value at base address = *arr + 1 = 10 + 1 = 11.
        //     }
        //     cout << endl;

        //     return 0;
        // }

//  4) Predict the output - level 3:
        // void solve(int* p) {
        //     *p = *p + 1;
        // }

        // int main() {
        //     int a = 5;
        //     int* p = &a;   // 'p' stores address of 'a'

        //     cout << "p = " << p << endl;   // 1004 (suppose)
        //     cout << "&p = " << &p << endl;   // 2004 (suppose)
        //     cout << "*p = " << *p << endl;   // 5

        //     solve(p);

        //     cout << "p = " << p << endl;   // 1004
        //     cout << "&p = " << &p << endl;   // 2004
        //     cout << "*p = " << *p << endl;   // 6

        //     return 0;
        // }

//  5) Predict the output - level 4:
        // void solve(int* p) {
        //     // pass by value
        //     p = p + 1;
        // }

        // int main() {
        //     int a = 5;
        //     int* p = &a;   // 'p' stores address of 'a'

        //     cout << "p = " << p << endl;   // 1004 (suppose)
        //     cout << "&p = " << &p << endl;   // 2004 (suppose)
        //     cout << "*p = " << *p << endl;   // 5

        //     solve(p);

        //     cout << "p = " << p << endl;   // 1004
        //     cout << "&p = " << &p << endl;   // 2004
        //     cout << "*p = " << *p << endl;   // 5

        //     return 0;
        // }

//  6) Predict the output - level 4:
        // void solve(int* &p) {
        //     // pass by reference
        //     p = p + 1;
        // }

        // int main() {
        //     int a = 5;
        //     int* p = &a;   // 'p' stores address of 'a'

        //     cout << "p = " << p << endl;   // 1004 (suppose)
        //     cout << "&p = " << &p << endl;   // 2004 (suppose)
        //     cout << "*p = " << *p << endl;   // 5

        //     solve(p);

        //     cout << "p = " << p << endl;   // 1004
        //     cout << "&p = " << &p << endl;   // 2004
        //     cout << "*p = " << *p << endl;   // prints a garbage value present at address next to 1004,
        //     // i.e. 1004 + sizeof(int) = 1004 + 4 = 1008.

        //     return 0;
        // }
