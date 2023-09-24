// In the range of 1 to n integers in a sorted array, any one integer is missing.
// Find the missing one.

// This problem is an implementation of binary search.

#include <iostream>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int findMissingElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <=end) {
        int diff = arr[mid] - mid;
        
        if(diff == 1) {
            start = mid + 1;
        } else {   // (diff == 2)
            ans = mid;
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ((ans+1)==0) ? n+1 : (ans+1);
    // ans contains the index of element just after which the sequence is broken,
    // thus we return (ans+1) to get that element.
    // if the last element of the sequence is missing, then ans == -1. Thus, to return
    // the last element of the sequence, we return n+1.
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int n = 8;

    cout << findMissingElement(arr, n);

    return 0;
}