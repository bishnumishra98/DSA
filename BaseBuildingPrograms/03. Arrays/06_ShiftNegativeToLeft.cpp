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
    // 'i' will be used to iterate each element, and 'j' will always point to first +ve number after chain of negative numbers,
    // i.e., all elements before 'j'th index will be -ve.
    int i = 0, j = 0;

    while(i < n) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        i++;
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
