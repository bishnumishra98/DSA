// If an element at 'ith' index in a sorted array is present at '(i-1)th', 'ith', or '(i+1th)'
// index in another array, then the another array can be called a "nearly sorted array".

// This problem is an implementation of binary search.

#include <iostream>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int searchNearlySorted(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {   // (mid-1 >= 0) and (mid+1 < n) conditions are checked to
       // prevent the runtime error: array index out of bound.
        if ((mid-1 >= 0) && (arr[mid - 1] == target)) {
            return mid - 1;
        }
        if (arr[mid] == target) {
            return mid;
        }
        if ((mid+1 < n) && (arr[mid + 1] == target)) {
            return mid + 1;
        }

        if (target > arr[mid]) {
            // we need not write 'start = mid + 1' unnecesaarily because element at 'mid+1'
           // index has already been compared with 'target' in 3rd if condition
            start = mid + 2;
        } else {   // if (target < arr[mid])
            // we need not write 'start = mid + 1' unnecesaarily because element at 'mid-1'
           // index has already been compared with 'target' in 1st if condition
            end = mid - 2;
        }

        mid = start + (end - start) / 2;
    }

    return -1; // if target not found
}


int main() {
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int n = 7;
    int target = 70;

    int index = searchNearlySorted(arr, n, target);

    cout << index;

    return 0;
}