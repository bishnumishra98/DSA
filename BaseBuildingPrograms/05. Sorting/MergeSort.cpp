// Merge sort is a popular comparison-based sorting algorithm that follows the divide-and-conquer
// paradigm to sort a list or array of elements. Here's how merge sort works on a high level:

// 1) Break the array into two equal halves. Let the array from index 0 to 'mid' be called left array,
//    and array from 'mid+1' to 'end' be called right array respectively.

// 2) Apply recursion on each of the two parts of the array to break it further into the same two halves.
//    This recursion will continue until we get an array of 1 element. This happens inside mergeSort() function.

// 3) Merge the sorted sub-arrays to produce a single sorted array. This is done by comparing elements from
//    the two sub-arrays and merging them in the correct order. This happens inside merge() function.

// For better illustration how this algorithm works, check out 'MergeSort.jpg'

#include <iostream>
using namespace std;

// merge() gets an array(which has two sorted subarrays), then it hypothetically divides that array
// from mid into two sorted parts and then joins them to make one temporary single sorted array. At last,
// it inserts elements of those temporary array into the array that merge() function had originally received.
void merge(int *arr, int start, int mid, int end) {
    int *temp = new int[end-start+1];   // creating an array named 'temp' of size 'end-start+1' inside heap.
    int left = start;   // index of left side of array will range from index 'start' to 'mid'
    int right = mid+1;   // index of right side of array will range from index 'mid+1' to 'end'

    // merging subarrays, i.e. comparing elements from both arrays and placing them in ascending order inside 'temp'
    int k = 0;
    while(left<=mid && right<=end) {
        if(arr[left] <= arr[right]) {
            temp[k] = arr[left];
            k++;
            left++;
        } else {
            temp[k] = arr[right];
            k++;
            right++;
        }
    }

    // if right array gets exhausted first, there will still be some elements remaining in left array.
    // So put the remaining elements of left array as it is in 'temp'.
    while(left <= mid) {
        temp[k] = arr[left];
        k++;
        left++;
    }

    // if left array gets exhausted first, there will still be some elements remaining in right array.
    // So put the remaining elements of right array as it is in 'temp'.
    while(right <= end) {
        temp[k] = arr[right];
        k++;
        right++;
    }

    // Take the sorted elements of 'temp' and put it directly in the original array, i.e., {20, 10, 50, 40, 30, 60} this one.
    for(int i=start; i<=end; i++) {
        arr[i] = temp[i-start];
    }

    delete[] temp;   // deallocating the 'temp' from heap
}

// T.C: O(nlogn);   where n = size of 'arr'
// S.C: O(n)
void mergeSort(int *arr, int start, int end) {
    // base case
    if(start >= end) {   // if 'start>end', it means an invalid array, and if
                        // 'start==end', only 1 element is left in sub-array
        return;
    }

    int mid = start + (end - start) / 2;   // or, (start+end)/2

    // Divide
    // dividing left part of array until base case is reached, i.e., only 1 element is left in array
    mergeSort(arr, start, mid);

    // dividing right part of array until base case is reached, i.e., only 1 element is left in array
    mergeSort(arr, mid+1, end);

    // Conquer
    // merging 2 sorted arrays
    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {20, 10, 50, 40, 30, 60};
    int size = 6;
    int start = 0;
    int end = size - 1;

    mergeSort(arr, start, end);

    for(int element: arr) {
        cout << element << " ";
    }

    return 0;
}
