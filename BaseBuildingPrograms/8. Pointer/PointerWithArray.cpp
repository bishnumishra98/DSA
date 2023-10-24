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
        // int arr[5] = {10, 20, 30, 40, 50};

        // // arr = arr + 1;   // compilation error because we are trying to modify a constant pointer. This
        // // is because the pointer 'arr' is pointing to memory location of the first element of the array,
        // // and we cannot change this address. However, we can make a copy of 'arr' and move forward.

        // int* ptr = arr;   // 'ptr' is copy of 'arr', i.e. 'ptr' is pointer to first element of array
        // ptr++;   // pointer now points to the second element of the array
        // cout << "*ptr = " << *ptr << endl;   // o/p: 20

//  5) Implementation of integer and character arrays with pointers
        // int arr[5] = {10, 20, 30, 40, 50};
        // char ch[5] = {'d', 'i', 's', 'h', 'a'};   // or we can write char ch[5] = "disha";

        // int* p_int = arr;
        // char* p_ch = ch;

        // cout << "p_int = " << p_int << endl;   // o/p: 0x61fef8, prints base address
        // cout << "p_ch = " << p_ch;   // o/p: disha, prints whole array

//  6) Predict the output - level 3:
        // char ch[50] = "disha";
        // char* ptr = ch;

        // cout << "ch = " << ch << endl;   // o/p: disha, prints whole array
        // cout << "&ch = " << &ch << endl;   // o/p: 104 (suppose), prints base address
        // cout << "ch[0] = " << ch[0] << endl;   // o/p: d, prints value at first index of array
        // cout << "ptr = " << ptr << endl;   // o/p: disha, prints whole array 
        // cout << "&ptr = " << &ptr << endl;   // o/p: 204 (suppose), prints address of 'ptr' pointer
        // cout << "ptr[0] = " << ptr[0] << endl;   // o/p: d, prints value at first index of array
        // cout << "*ptr = " << *ptr << endl;   // o/p: d, *ptr = *(ptr + 0) = ptr[0]; thus it prints value at first index of array

//  7) Pointer to base address of an array VS pointer to an array
        int arr[5] = {10, 20, 30, 40, 50};
        int* ptr = arr;   // pointer to base address of array
        int* ptr2 = &arr[0];   // pointer to base address of array
        int(* ptr3)[5] = &arr;   // pointer to an array of 5 integers, initialized with the address of the array arr

        cout << "ptr = " << ptr << endl;   // 104 (suppose)
        cout << "*ptr = " << *ptr << endl;   // 10
        cout << "ptr2 = " << ptr2 << endl;   // 104 (suppose)
        cout << "*ptr2 = " << *ptr2 << endl;   // 10
        cout << "ptr3 = " << ptr3 << endl;   // 104 (suppose)
        cout << "*ptr3 = " << *ptr3 << endl;   // 104 (suppose)
        cout << "*ptr3[0] = " << *ptr3[0] << endl;   // 10



    return 0;
}