// Given an array where all elements occur in pairs and no element can occur more than twice
// back to back. Only one element exists odd number of times. Find the odd occurring element.
// i/p: [10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10], o/p: 2

// This problem can be solved using XOR operator in O(n), but can also be solved using binary search in O(logn) time.

#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(1)
int findOddOccurringElement_XOR(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans ^= arr[i];
    }
    return ans;
}

// Algorithm: It is very simple. We know that all elements would occur back to back twice, except the one that occurs
//            odd no. of times. Due to that odd occuring element, the indexing pattern gets changed for later elements.
//            Array: {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10}
//            Index:   0   1  2  3  4  5  6  7  8   9  10  11  12  13  14
// 1. Initialize start = 0, mid = start + end / 2, and end = n - 1. While start <= end, check the position of 'mid':
//    'mid' can lie on either an odd index (eg: 1, 3, 5, etc.) or even index (eg: 0, 2, 4, etc.).

//    Case 1: If 'mid' lies on an odd index:
//            In this case, there can two sub-cases:
//            Case I:   The 'mid' lies on an index that lies before the odd occurring element, i.e., arr[mid] == arr[mid - 1]:
//                      In this case, we know the odd occurring elements is present on the right, thus shift rightwards,
//                      i.e., start = mid + 1.
//            Case II:  The 'mid' lies on an index that lies after the odd occurring element, i.e., arr[mid] == arr[mid + 1]:
//                      In this case, we know the odd occurring elements is present on the left, thus shift leftwards,
//                      i.e., end = mid - 1.
//            Case III: The 'mid' lies on the odd occuring element. This is not possible as all elements occur in pairs.
//                      Thus, the odd occuring element will always be present on an even index.

//    Case 2: If 'mid' lies on an even index:
//            In this case, there can three sub-cases:
//            Case I:  The 'mid' lies on an index that lies before the odd occurring element, i.e., arr[mid] == arr[mid + 1]:
//                     In this case, we know the odd occurring elements is present on the right, thus shift rightwards,
//                     i.e., start = mid + 2. No need to do 'mid + 1', as it is already done in Case 1.I.
//            Case II: The 'mid' lies on an index that lies after the odd occurring element, i.e., arr[mid] == arr[mid - 1]:
//                     In this case, we know the odd occurring elements is present on the left, thus shift leftwards,
//                     i.e., end = mid - 2. No need to do 'mid - 1', as it is already done in Case 1.II.
//            Case III: The 'mid' lies on the odd occuring element, i.e., arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]:
//                      Thus, the odd occuring element is found. So return it, i.e., return arr[mid].


// T.C: O(logn)
// S.C: O(1)
int findOddOccurringElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = 0;

    while(start <= end) {
        if(mid & 1) {   // if 'mid' lies on an odd index
            if(mid - 1 >= 0 && arr[mid] == arr[mid - 1]) start = mid + 1;
            else if(mid + 1 < n && arr[mid] == arr[mid + 1]) end = mid - 1;
        } else {   // if 'mid' lies on an even index
            if(mid + 1 < n && arr[mid] == arr[mid + 1]) start = mid + 2;
            else if(mid - 1 >= 0 && arr[mid] == arr[mid - 1]) end = mid - 2;
            else if(mid + 1 < n && mid - 1 >= 0 && arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                ans = mid;
                break;
            };
        }

        mid = start + (end - start) / 2;
    }

    return arr[ans];
}


int main() {
    int arr[] = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10};
    int n = 15;

    // cout << findOddOccurringElement_XOR(arr, n);

    cout << findOddOccurringElement(arr, n);

    return 0;
}
