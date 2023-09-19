#include <iostream>
#include <algorithm>   // for reverse()
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// T.C: O(n)
// S.C: O(n)
void reverseArray_bruteForce(int arr[], int n) {
    int* reversedArr = new int[n];

    for (int i = 0; i < n; i++) {
        reversedArr[i] = arr[n - 1 - i];
    }

    // Copy the reversed array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = reversedArr[i];
    }

    delete[] reversedArr;
}

// T.C: O(n)
// S.C: O(1)
void reverseArray_STL(int arr[], int n) {
    reverse(arr, arr + n);
}

// T.C: O(n)
// S.C: O(1)
void reverseArray_twoPointer(int arr[], int n) {
    int* start = arr;   // start = first index(0) of array
    int* end = arr + n - 1;   // end = last index(n-1) of array

    while (start < end) {
        swap(*start, *end);   // Swap elements pointed by start and end.
                             // swap() has a T.C and S.C of O(1) respectively.
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    reverseArray_bruteForce(arr, n);
    printArray(arr, n);
    cout << endl << endl;

    reverseArray_STL(arr, n);
    printArray(arr, n);
    cout << endl << endl;

    reverseArray_twoPointer(arr, n);
    printArray(arr, n);

    return 0;
}