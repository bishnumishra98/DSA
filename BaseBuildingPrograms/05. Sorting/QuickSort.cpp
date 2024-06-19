// Quick Sort is a popular sorting algorithm that uses a divide-and-conquer strategy to sort elements
// in an array or list. It works by selecting a pivot element and partitioning the array into two
// sub-arrays according to the pivot. Elements less than the pivot are placed to its left, and
// elements greater than the pivot are placed to its right. This process is then applied recursively
// to the sub-arrays, and finally the array gets sorted.

#include <iostream>
using namespace std;

// T.C: O(nlogn);   where n = size of array.
//                  However, worst time complexity of quickSort is O(n^2), when pivot is chosen as the biggest element of array.
// S.C: O(1)
void quickSort(int *arr, int start, int end) {
    // base case
    if(start >= end) return;

    int pivot = end;
    int i = start - 1;
    int j = start;

    while(j < pivot) {
        if(arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    i++;
    swap(arr[i], arr[pivot]);   // pivot element comes to its correct index at this step

    // element at ith index has all elements smaller than it on its left, and all elements larger
    // than it on its right. Then, we do quickSort for sub-array on its left and right also.
    quickSort(arr, start, i-1);
    quickSort(arr, i+1, end);
}

int main() {
    int arr[] = {10, 50, 30, 20, 40};
    int size = 5;
    int start = 0;
    int end = size - 1;

    quickSort(arr, start, end);

    for(int element: arr) {
        cout << element << " ";
    }

    return 0;
}