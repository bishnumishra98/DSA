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
int findOddOccurringElement(int nums[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    int ans = -1;   // the single element will be stored in it

     //  i/p: [1, 1, 2, 3, 3, 4, 4, 8, 8], o/p: 2
    // Index:  0  1  2  3  4  5  6  7  8

    while(start <= end) {
        // 'mid-1 >= 0' and 'mid+1 < n' conditions are written to avoid runtime error: array index out of bound

        if(mid & 1) {   // 'mid & 1' returns true for odd numbers, i.e. if 'mid'
                                        // is at odd index. We have 2 possible cases here.
            if((mid-1 >= 0) && (nums[mid] == nums[mid-1])) {
                // It means 'mid' is at left of 'ans'. In this case, we move to right.
                start = mid + 1;
            } else {
                // 'mid' is at right of 'ans'. In this case, we move to left.
                end = mid - 1;
            }
        } else {   // 'mid' is at even index. We have 3 possible cases here.
            if((mid-1 >= 0) && nums[mid] == nums[mid-1]) {
                // 'mid' is at right of 'ans'. In this case, we move to left.
               // 'mid-1' is already checked, so there's no point of unnecessarily
              // bringing 'end' to 'mid-1'
                end = mid - 2;
            } else if((mid+1 < n) && nums[mid] == nums[mid+1]) {
                // 'mid' is at left of 'ans'. In this case, we move to right.
               // 'mid+1' is already checked, so there's no point of unnecessarily
              // bringing 'start' to 'mid+1'
                start = mid + 2;
            } else {
                // 'mid' is on 'ans'
                ans = mid;
                break;   // break the loop as 'ans' is found
            }
        }

        mid = start + (end - start)/2;
    }

    return nums[ans];
}


int main() {
    int arr[] = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10};
    int n = 15;

    // cout << findOddOccurringElement_XOR(arr, n);

    cout << findOddOccurringElement(arr, n);

    return 0;
}