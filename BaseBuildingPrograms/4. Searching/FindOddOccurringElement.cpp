// Given an array where all elements occur in pairs and no element can occur more than twice
// back to back. Only one element exists odd number of times. Find the odd element.
// i/p: [10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10], o/p: 2
// Find odd occurring element within O(logn) time complexity.

// This problem is an implementation of binary search.

#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(1)
int findOddOccurringElement_XOR(int arr[], int n) {
    int ans = 0;

    for(int i=0; i<n; i++) {
        ans ^= arr[i];
    }

    return ans;
}

// T.C: O(logn)
// S.C: O(1)
int findOddOccurringElementIndex(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(start == end) {
            return start;
        }

        if(mid & 1) {   // 'mid&1' returns true for odd numbers, i.e. if mid is at odd index
            if((mid-1 >= 0) && (arr[mid] == arr[mid-1])) {
                // left me hu, right me jao
                start = mid + 1;
            } else {
                // right me hu, left me jao
                end = mid - 1;
            }
        } else {   // if mid is at even index
            if((mid+1 < n) && (arr[mid] == arr[mid+1])) {
                // left me hu, right me jao
                start = mid + 2;
            } else {
                // right me hu ya to mei ans pe hu, left me jao
                // But keep in mind, 'end = mid-1' se ans lost ho skta hai. So go to left by 'end = mid'
                end = mid;
            }
        }
        // 'mid-1 >= 0' and 'mid+1 < n' conditions are written to avoid runtime error: array index out of bound

        mid = start + (end - start)/2;
    }

    return -1;   // if odd occurring element not found
}


int main() {
    int arr[] = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10};
    int n = 15;

    // cout << findOddOccurringElement_XOR(arr, n);

    cout << arr[findOddOccurringElementIndex(arr, n)];

    return 0;
}