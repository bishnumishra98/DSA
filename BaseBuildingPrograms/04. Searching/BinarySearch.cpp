// Note that Binary Search applies on only sorted arrays, i.e monotonic functions

#include <iostream>
using namespace std;

// Binary search.
// T.C: O(logn)
// S.C: O(1)
int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;   // same as (start + end)/2

    while(start <= end) {   // start == end is the case, when only 1 element is left in array
        if(target == arr[mid]) {
            return mid;
        } else if(target > arr[mid]) {
            start = mid + 1;   // go in right part
        } else {   // if(target < arr[mid])
            end = mid - 1;   // go in left part
        }

        mid = start + (end - start)/2;   // updating mid
    }
    
    return -1;
}


int main() {
    int arr[] = {10, 20, 30, 40, 71, 86};
    int n = 7;
    int target = 40;

    int result = binarySearch(arr, n, target);

    if(result != -1) {
        cout << "Element found at index: " << result;
    } else {
        cout << "Element not found";
    }

    return 0;
}