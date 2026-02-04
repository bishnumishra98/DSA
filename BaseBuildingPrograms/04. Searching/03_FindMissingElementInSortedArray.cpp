// In the range of 1 to n integers in a sorted array, any one integer is missing. Find the missing one.
// Example 1:
// Input: arr[] = {1, 2, 3, 4, 5, 7, 8, 9}, n = 8
// Output: 6

// Example 2:
// Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}, n = 8
// Output: 9

// Bruteforce Algorithm:
// This problem can be done with XOR operator in O(n), but we can do the same with BS in O(logn).

// Optimal Algorithm: It is very easy.
//                    Array: {1, 2, 3, 4, 5, 7, 8, 9}
//                    Index:  0  1  2  3  4  5  6  7
//                    We can clearly see that element = index + 1, for all elements until a missing element comes.
//                    After a missing element, the equation becomes element = index + 2.
// 1. Initialize start = 0, mid = (start + end) / 2, end = n - 1. While start <= end, check:
//    Case 1: If arr[mid] - mid = 1
//            In this case, the missing element will be found on right side. Thus, shift rightwards, i.e., start = mid + 1.
//    Case 2: If arr[mid] - mid = 2
//            In this case the missing element will be found on left side. Thus, shift leftwards, i.e., end = mid - 1.
//            But it can also be a possibility that the just left element is again the one where arr[mid] - mid will be 1.
//            In simple words, we may be on the element that is just after the missing element. In this case, the loop
//            'start <= end' will terminate just after store the current iteration. Thus, store the current element's index
//            in any variable say 'ans', before shifting leftwards.
// 2. When the loop terminates, if 'ans' contains nothing, it means no missing element was found in the array, then
//    in this case the missing element is element after the last element, i.e., n + 1 where n is the size of the array;
//    else 'ans' contains the index of the element from where the difference of 2 between arr[mid] and mid started.
//    Thus, the missing element will obviously be 'ans + 1'.

#include <iostream>
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int findMissingElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start <= end) {
        if(arr[mid] - mid == 1) start = mid + 1;
        else {
            ans = mid;
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return (ans == -1) ? n + 1 : ans + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int n = 8;

    cout << findMissingElement(arr, n);

    return 0;
}
