// Quick Sort is a popular sorting algorithm that uses a divide-and-conquer strategy to sort elements
// in an array or list. It works by selecting a pivot element and partitioning the array into two
// sub-arrays according to the pivot. Elements less than the pivot are placed to its left, and
// elements greater than the pivot are placed to its right. This process is then applied recursively
// to the sub-arrays, and finally the array gets sorted.

#include <iostream>
using namespace std;

// Partition function to divide the array into two parts
int partition(int arr[], int low, int high) {
    int pivot = arr[low];   // considering first element of array as pivot
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i <= high-1) i++;   // Move i to the right while elements are less than or equal to pivot and within bounds
        while(arr[j] > pivot && j >= low+1) j--;   // Move j to the left while elements are greater than pivot and within bounds
        if(i < j) swap(arr[i], arr[j]);   // If i is still less than j, swap elements at i and j
    }
    
    swap(arr[low], arr[j]);   // Swap pivot element with the element at j to place the pivot in its correct position
    return j;   // Return the partition index
}

// T.C: O(nlogn);   where n = size of array.
//                  However, worst time complexity of quickSort is O(n^2), when pivot is chosen as the biggest element of array.
// S.C: O(logn);   due to recursive stack.
//                 However, worst case space complexity is O(n). 
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    int arr[] = {10, 50, 30, 20, 40, 20, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = size - 1;

    quickSort(arr, low, high);

    for(int element: arr) {
        cout << element << " ";
    }

    return 0;
}



/*
// Lakshay bhaiya code for quickSort()
// T.C: O(nlogn);   where n = size of array.
//                  However, worst time complexity of quickSort is O(n^2), when pivot is chosen as the biggest element of array.
// S.C: O(logn);   due to recursive stack.
//                 However, worst case space complexity is O(n).
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
*/
