// Merge Sort: A Divide-and-Conquer Sorting Algorithm. The array is divided into two halves recursively until
//             each sub-array contains a single element, and then these sub-arrays are merged back together in
//             sorted order to produce the final sorted array.

// Illustration:
// Unsorted array: {45, 35, 55, 15, 25}, n = 5

// Step 1: Divide the array into two halves recursively until each sub-array contains a single element.
//         {45, 35, 55, 15, 25}
//         /                 \
//     {45, 35, 55}          {15, 25}
//      /       \            /      \
//  {45, 35}   {55}       {15}     {25}
//   /     \
// {45}   {35}

// Step 2: Merge the sub-arrays back together in sorted order.
// {45}   {35}
//   \     /
//   {35, 45}   {55}      {15}     {25}
//      \       /           \      /
//      {35, 45, 55}        {15, 25}
//           \               /
//         {15, 25, 35, 45, 55}

// Sorted array: {15, 25, 35, 45, 55}

// Video link: https://www.youtube.com/watch?v=4VqmGXwpLqc

// Here's how merge sort works on a high level:

// Algorithm:
// 1) Break the array into two equal halves. Let the array from index 0 to 'mid' be called left array,
//    and array from 'mid + 1' to 'end' be called right array respectively. Apply recursion on each of the two
//    parts of the array to break it further into the same two halves. This recursion will continue until we get
//    an array of 1 element. This happens inside mergeSort() function.
// 2) Merge the sorted sub-arrays to produce a single sorted array. This is done by comparing elements from
//    the two sub-arrays and merging them in the correct order. This happens inside merge() function.

#include <iostream>
#include <vector>
using namespace std;

// merge() gets an array(which has two sorted subarrays), then it hypothetically divides that array
// from mid into two sorted parts and then joins them to make one temporary single sorted array. At last,
// it inserts elements of those temporary array into the array that merge() function had originally received.
void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp(end - start + 1);   // creating an array named 'temp' of size 'end - start + 1'
    int left = start;   // index of left side of array will range from index 'start' to 'mid'
    int right = mid + 1;   // index of right side of array will range from index 'mid + 1' to 'end'

    // Merging subarrays, i.e., comparing elements from both arrays and placing them in ascending order inside 'temp'
    int k = 0;
    while(left <= mid && right <= end) {
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

    // If right array gets exhausted first, there will still be some elements remaining in left array.
    // So put the remaining elements of left array as it is in 'temp'.
    while(left <= mid) {
        temp[k] = arr[left];
        k++;
        left++;
    }

    // If left array gets exhausted first, there will still be some elements remaining in right array.
    // So put the remaining elements of right array as it is in 'temp'.
    while(right <= end) {
        temp[k] = arr[right];
        k++;
        right++;
    }

    // Take the sorted elements of 'temp' and put it directly in the original array 'arr' at respective indices.
    for(int i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
}

void ms(vector<int>& arr, int start, int end) {
    // Base case: 'start > end' means invalid array, and 'start == end' means only 1 element is left in sub-array
    if(start >= end) return;

    int mid = start + (end - start) / 2;   // (start + end) / 2

    // Step 1: Divide
    // dividing left part of array until base case is reached, i.e., only 1 element is left in array
    ms(arr, start, mid);

    // dividing right part of array until base case is reached, i.e., only 1 element is left in array
    ms(arr, mid + 1, end);

    // Step 2: Conquer
    // merging 2 sorted arrays
    merge(arr, start, mid, end);
}

// T.C: O(nlogn);   where n = size of 'arr'
// S.C: O(n)
void mergeSort(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1; 
    ms(arr, start, end);
}


int main() {
    vector<int> arr = {20, 10, 50, 40, 30, 60};

    mergeSort(arr);

    for(int element: arr) {
        cout << element << " ";
    }

    return 0;
}
