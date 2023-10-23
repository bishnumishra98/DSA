#include <iostream>
using namespace std;

int main() {
//  1) Base address of array: arr, &arr, &arr[0] all point to base address of array
        // int arr[5] = {10, 20, 30, 40, 50};

        // cout << "arr[0] = " << arr[0] << endl;   // 10
        // cout << "&arr[0] = " << &arr[0] << endl;   // 104 (suppose), address of arr[0], it is also called base address
        // cout << "arr = " << arr << endl;   // 104, base address of array
        // cout << "&arr = " << &arr << endl;   // 104, base address 

//  2) Predict the output - level 1:
        // int arr[5] = {10, 20, 30, 40, 50};

        // cout << "arr[0] = " << arr[0] << endl;   // 10 
        // cout << "&arr[0] = " << &arr[0] << endl;   // 104 (suppose), address of first index, i.e. base address
        // cout << "arr = " << arr << endl;   // 104, base address
        // cout << "&arr = " << &arr << endl;   // 104, base address
        // cout << "*arr = " << *arr << endl;   // 10, as arr contains 104, so *arr points to 10
        // cout << "*arr + 1 = " << *arr + 1 << endl;   // 10 + 1 = 11
        // cout << "*(arr) + 1 = " << *(arr) + 1 << endl;   // 10 + 1 = 11
        // cout << "*(arr + 1) = " << *(arr + 1) << endl;   // 20, as value stored at 104+4, i.e. at 108, is 20
        // cout << "*(arr + 2) = " << *(arr + 2) << endl;   // 30, as value stored at 104+8, i.e. at 112, is 30
        // cout << "*(arr + 3) = " << *(arr + 3) << endl;   // 40, as value stored at 104+12, i.e. at 116, is 40

//  3) Predict the output - level 2:
        // int arr[5] = {10, 20, 30, 40, 50};

        // for(int i=0; i<5; i++) {
        //     cout << arr[i] << " ";   // 10 20 30 40 50
        // }
        // cout << endl;
        // for(int i=0; i<5; i++) {
        //     cout << i[arr] << " ";   // 10 20 30 40 50
        // }
        // // Amazing fact: arr[i] and i[arr] mean the same in C/C++, as they both are internally converted
        // // like this: *(arr + i) and *(i + arr) respectively, where arr = base address of array

//  4) POINTER ARITHMETIC in arrays
        int arr[5] = {10, 20, 30, 40, 50};

        // arr = arr + 1;   // compilation error

    return 0;
}