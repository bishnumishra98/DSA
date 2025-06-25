#include <iostream>
using namespace std;

// T.C: O(n/2)
// S.C: O(n/2)
void reverseArray_twoPointer(int arr[], int i, int j) {
    if(i >= j) return;   // Base case: Return when i reaches j
    swap(arr[i], arr[j]);
    reverseArray_twoPointer(arr, i+1, j-1);
}

// T.C: O(n/2)
// S.C: O(n/2)
void reverseArray_onePointer(int arr[], int i, int n) {
    if(i >= n/2) return;   // Base case: Return when i reaches n/2
    swap(arr[i], arr[n-i-1]);   // swapping first with last element, 2nd with 2nd last element, and so on.
    reverseArray_onePointer(arr, i+1, n);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = 7;

    int i = 0;
    int j = n - 1;
    reverseArray_twoPointer(arr, i, j);
    cout << "Reversed array: " << endl;

    for(int i: arr) {
        cout << i << " ";
    }

    cout << endl;
    reverseArray_onePointer(arr, i, n);
    cout << "Reversed array: " << endl;

    for(int i: arr) {
        cout << i << " ";
    }

    return 0;
}
