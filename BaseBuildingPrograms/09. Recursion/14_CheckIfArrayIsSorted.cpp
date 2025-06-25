#include <iostream>
using namespace std;

// T.C: O(size)
// S.C: O(size)
bool checkIfArrayIsSorted(int *arr, int size, int index) {
    // base case
    if(index >= size) {
        return true;
    }

    // processing
    if(arr[index] > arr[index-1]) {
        // recursive relation
        return checkIfArrayIsSorted(arr, size, index+1);
    } else {
        return false;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 1;

    if(checkIfArrayIsSorted(arr, size, index)) {
        cout << "Array is sorted";
    } else {
        cout << "Array is unsorted";
    }

    return 0;
}
