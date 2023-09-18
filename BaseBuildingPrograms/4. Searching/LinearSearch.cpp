#include <iostream>
using namespace std;

// Brute force
// T.C: O(n)
// S.C: O(1)
int linearSearch(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, -25, 30, -32, 71, 56};
    int n = 7;
    int target = -32;

    int result = linearSearch(arr, n, target);

    if(result != -1) {
        cout << "Element found at index: " << result;
    } else {
        cout << "Element not found";
    }

    return 0;
}