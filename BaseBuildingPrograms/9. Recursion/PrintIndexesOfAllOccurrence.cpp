#include <iostream>
using namespace std;

// T.C:
// S.C:
void printIndexesOfAllOccurrenceOfTarget(int *arr, int size, int index, int target) {
    // base case
    if(index >= size) {
        return;
    }

    // processing
    if(arr[index] == target) {
        cout << index << " ";
    }

    // recursive relation
    printIndexesOfAllOccurrenceOfTarget(arr, size, index+1, target);
}

int main() {
    int arr[] = {10, 20, 30, 20, 50, 10, 50, 30, 30, 10};
    int size = 10;
    int index = 0;
    int target = 50;

    printIndexesOfAllOccurrenceOfTarget(arr, size, index, target);

    return 0;
}