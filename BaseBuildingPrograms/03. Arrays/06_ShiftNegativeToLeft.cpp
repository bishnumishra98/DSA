// love babbar practice problem
// Example:
// Input:
// {-2, 3, 5, -10, 9, -7, 11, -6}
// Output:
// {-2, -10, -7, -6, +ve numbers}

#include <iostream>
using namespace std;

// Two pointer approach
// T.C: O(n)
// S.C: O(1)
void shiftNegativeToLeft(int arr[], int n) {
    int j = 0;   // all elements before j will be a negative number

    // Iterate each element of arr, and if arr[i] is a negative number, swap it with arr[j], so that one more
    // element gets added to the chain of negative numbers. And then move j ahead to update the new position of j.
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int arr[] = {-2, 3, 5, -10, 9, -7, 11, -6};
    int n = 8;

    shiftNegativeToLeft(arr, n);

    // printing array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
