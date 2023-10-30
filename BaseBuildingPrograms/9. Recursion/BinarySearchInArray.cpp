#include <iostream>
using namespace std;

// T.C: O(log(size))
// S.C: O(log(size))
int binarySearch(int *arr, int start, int end, int target) {
    // base case
    if(start > end) {
        return -1;
    }

    // processing
    int mid = start + (end-start)/2;
    if(target == arr[mid]) {
        return mid;
    } else if(target > arr[mid]) {
        start = mid + 1;
        // recursive relation
        return binarySearch(arr, start, end, target);
    } else {
        end = mid - 1;
        // recursive relation
        return binarySearch(arr, start, end, target);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int start = 0;   // starting index
    int end = size - 1;   // last index
    int target = 50;

    if(binarySearch(arr, start, end, target) == -1) {
        cout << "Target not found";
    } else {
        cout << "Target found at index " << binarySearch(arr, start, end, target);
    }

    return 0;
}