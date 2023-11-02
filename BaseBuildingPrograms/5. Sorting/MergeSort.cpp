// Merge sort is a popular comparison-based sorting algorithm that follows the divide-and-conquer
// paradigm to sort a list or array of elements. Here's how merge sort works on a high level:

// 1) Break the array into two equal halves. Let the array from index 0 to 'mid' be called left array,
//    and array from 'mid+1' to 'end' be called right array respectively.

// 2) Apply recursion on each of the two parts of the array to break it further into two equal halves.
//    This recursion will continue until we get an array of 1 element.

// 3) Merge back the sub-arrays in a sorted order. This involves comparing elements from both sub-arrays
//    and placing them in the correct order.

#include <iostream>
using namespace std;

// merge() gets an array, it divides the array into two halves and then joins them in sorted order
void merge(int *arr, int start,int end) {
    int mid = start + (end - start) / 2;   // or, (start+end)/2

    int len_left = mid - start + 1;   // length of left sub-rray
    int len_right = end - mid;   // length of right sub-array

    // creating left and right sub-array
    int *left_array = new int[len_left];   // creating an array 'left_array' of size 'len_left'
    int *right_array = new int[len_right];   // creating an array 'right_array' of size 'len_right'

    // copying elements from mother array to 'left_array'
    // 'left_array' will have elements which are at index of 0 to 'mid' of mother array
    for(int i=0; i<len_left; i++) {
        left_array[i] = arr[start + i];
    }

    // copying elements from mother array to 'right_array'
    // 'right_array' will have elements which are at index of 'mid+1' to 'end' of mother array
    for(int i=0; i<len_right; i++){
        right_array[i] = arr[mid + 1 + i];
    }

    // Mother array is divided in two halves and copied into 'left_array' and 'right_array'. Now we will
    // just merge the two parts in ascending order. Note that 'left_array' and 'right_array' are already
    // sorted. We just need to merge two sorted arrays into one using two pointer approach. The one
    // array we get here is not any new array, but we will insert elements in mother array itself.

    // Question: How are 'left_array' and 'right_array' are already sorted ?
    // Answer: When the merge() function is called 1st time, the mother array contains 2 elements,
    // and the 'left_array' and 'right_array' each contains 1 elements. Then they are merged to form
    // one sorted array. Then, this sorted array becomes 'left' part of a mother array.
    // The 2nd time the merge() function is called, again the mother array contains 2 elements,
    // and the 'left_array' and 'right_array' each contains 1 elements. Then they are merged to form
    // one sorted array. Then, this sorted array becomes 'right' part of a mother array.
    // The 3rd time the merge() function is called, this time the mother array contains 4 elements,
    // and the 'left_array' and 'right_array' each contains 2 elements in sorted order. Then they are
    // merged to form one sorted array. Then, this sorted array becomes 'left' part of a mother array.
    // The 4th time the merge() function is called, this time the mother array contains 4 elements,
    // and the 'left_array' and 'right_array' each contains 2 elements in sorted order. Then they are
    // merged to form one sorted array. Then, this sorted array becomes 'right' part of a mother array.
    // And this process continues until the whole array gets sorted.
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while(leftIndex<len_left && rightIndex<len_right) {
        if(left_array[leftIndex] < right_array[rightIndex]) {
            arr[mainArrayIndex] = left_array[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right_array[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // But 2 more cases may be still be left after the above operation of inserting elements into mother array:
    // i)  All elements in 'left_array' have been traversed and put into mother array, thus 'leftIndex'
    //     reached 'len_left-1', due to which while() loop ended and some elements in 'right_array' are
    //     still remaining to be traversed and put into the mother array.
    //     In this case, we exactly copy the remaining elements of 'right_array' into mother array.
    while(rightIndex < len_right) {
        arr[mainArrayIndex] = right_array[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // ii) All elements in 'right_array' have been traversed and put into mother array, thus 'rightIndex'
    //     reached 'len_right-1', due to which while() loop ended and some elements in 'right_array' are
    //     still remaining to be traversed and put into the mother array.
    //     In this case, we exactly copy the remaining elements of 'right_array' into mother array.
    while(leftIndex < len_left) {
        arr[mainArrayIndex] = left_array[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    delete[] left_array;   // deallocating the 'left_array' from heap
    delete[] right_array;   //// deallocating the 'right_array' from heap
}

// T.C: O(nlogn);   where n = size of 'arr'
// S.C: O(n)
void mergeSort(int *arr, int start, int end) {
    // base case
    if(start >= end) {   // if 'start>=end', it means only 1 element is left in sub-array
        return;
    }

    int mid = start + (end - start) / 2;   // or, (start+end)/2

    // Applying recursive call on left sub-array to break it further into 2 parts until
    // we reach base case, i.e. only 1 element is left in sub-array
    mergeSort(arr, start, mid);   // last index of left sub-array is 'mid'

    // Applying recursive call on right sub-array to break it further into 2 parts until
    // we reach base case, i.e. only 1 element is left in sub-array
    mergeSort(arr, mid+1, end);   // first and last indexes of right sub-array is 'mid+1' and 'end' resp

    // merging 2 sorted sub-arrays
    merge(arr, start, end);
}

int main() {
    int arr[] = {10, 50, 30, 20, 40};
    int size = 5;
    int start = 0;
    int end = size - 1;

    mergeSort(arr, start, end);

    for(int element: arr) {
        cout << element << " ";
    }

    return 0;
}