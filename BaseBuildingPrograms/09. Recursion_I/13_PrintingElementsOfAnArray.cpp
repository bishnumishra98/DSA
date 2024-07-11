#include <iostream>
using namespace std;

// T.C: O(size)
// S.C: O(size)
void printArray(int *arr, int size, int index) {
    // base case
    if(index >= size) {
        return;
    }

    // processing
    cout << arr[index] << " ";

    // recursive relation
    printArray(arr, size, index+1);
}

// T.C: O(size)
// S.C: O(size)
void printReverseArray(int *arr, int size, int index) {
    // base case
    if(index >= size) {
        return;
    }

    // recursive relation
    printReverseArray(arr, size, index+1);

    // processing
    cout << arr[index] << " ";
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    printArray(arr, size, 0);
    cout << endl;
    printReverseArray(arr, size, 0);

    return 0;
}
