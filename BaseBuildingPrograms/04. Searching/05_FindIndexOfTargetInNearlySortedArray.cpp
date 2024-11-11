// If an element at 'ith' index in a sorted array is present at '(i-1)th', 'ith', or '(i+1th)'
// index in another array, then the another array can be called a "nearly sorted array".

// Algorithm: Extremely simple.
// As we know that nearly sorted array has array rotated by 1 element only, we can handle the two extra
// case separately and add them in usual Binary search algorithm. So total there will be 5 cases:

// Extra cases:
// Case 1: if(arr[mid - 1] == target)
//         In this case, simply return the index 'mid - 1'.
// Case 2: if(arr[mid + 1] == target)
//         In this case, simply return the index 'mid + 1'.

// Usual binary search cases:
// Case 3: if(target < arr[mid])
//         In this case, simply shift leftwards, i.e., end = mid - 2. Note that no need of unnecessarily do 'end = mid - 1',
//         because 'mid - 1' is already checked in case 1 and it does not contains the target.
// Case 4: if(target > arr[mid])
//         In this case, simply shift rightwards, i.e., start = mid + 2. Note that no need of unnecessarily do 'start = mid + 1',
//         because 'mid + 1' is already checked in case 2 and it does not contains the target.
// Case 5: if(target == arr[mid])
//         In this case, target is found so simply return 'mid' index.

#include <iostream>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int searchNearlySorted(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if(mid - 1 >= 0 && arr[mid - 1] == target) return mid - 1;
        else if(mid + 1 < n && arr[mid + 1] == target) return mid + 1;
        else if(target < arr[mid]) end = mid - 2;
        else if (target > arr[mid]) start = mid + 2;
        else return mid;   // if(target == arr[mid])

        mid = start + (end - start) / 2;
    }

    return -1;   // if target not found
}


int main() {
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int n = 7;
    int target = 70;

    int index = searchNearlySorted(arr, n, target);

    cout << index;

    return 0;
}
