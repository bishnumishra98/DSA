#include <iostream>
using namespace std;

// Brute force
// T.C: O(n)
// S.C: O(1)
bool linearSearch(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {10, 20, -25, 30, -32, 71, 56};
    int n = 7;
    int target = 31;

    if(linearSearch(arr, n, target)) {
        cout << "Element found";
    } else {
        cout << "Element not found";
    }

    return 0;
}