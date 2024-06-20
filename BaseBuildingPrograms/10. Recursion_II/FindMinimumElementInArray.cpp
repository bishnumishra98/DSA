#include <iostream>
#include <limits.h>
using namespace std;

// T.C: O(size)
// S.C: O(size)
// linear search approach
void findMinElement(int *arr, int size, int index, int &mini) {
    // base case
    if(index >= size) {   // when entire array is traversed, return
        return;
    }

    // processing
    mini = min(mini, arr[index]);

    // recursive relation
    findMinElement(arr, size, index+1, mini);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    int size = 5;
    int index = 0;
    int mini = INT_MAX;

    findMinElement(arr, size, index, mini);

    cout << "Minimum element: " << mini;

    return 0;
}