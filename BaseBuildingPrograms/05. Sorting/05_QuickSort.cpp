// Quick Sort: We pick a element called pivot element, and partition the array around the pivot such that all elements on left
//             of pivot are smaller than or equal to pivot, and all elements on right of pivot are greater than pivot. Then,
//             we recursively apply the same logic to left and right sub-arrays of pivot and finally the whole array gets sorted.

// ● How to partition the array around the pivot element ?
//   1. Choose a pivot element. Here, we are choosing the first element of the array as pivot.
//   2. Take two pointers i and j. Initialize i to the first index and j to the last index of the array.
//   3. Increment i till we find an element greater than pivot. Decrement j till we find an element smaller than or equal to pivot.
//      Hence, i stands at the first element encountered from left which is greater than pivot, and j stands at the first element
//      encountered from right which is smaller than or equal to pivot.
//   4. If i is still less than j, it means we have found two elements which are at wrong halves, so we swap them. Repeat
//      steps 3 and 4 till i meets or crosses j.
//   5. Once i meets or crosses j, j comes to the region where every element is smaller than or equal to pivot. So, we swap the
//      pivot element with the element at j. Now, pivot is at its correct position.
//   6. Return j as the partition index, .i.e., the correct index of pivot element.

// Video link: https://www.youtube.com/watch?v=WIrA4YexLRQ&t=417s


#include <iostream>
#include <vector>
using namespace std;

// Partition function returns the correct index of the pivot element and segregates the array around the pivot element
// such that all elements on left of pivot are smaller than or equal to pivot, and all elements on right of pivot are greater
// than or equal to pivot.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];   // considering first element of array as pivot, i.e., arr[low]
    int i = low;
    int j = high;

    while(i < j) {
        while(i <= high - 1 && arr[i] <= pivot) i++;   // increment i till we find an element greater than pivot
        while(j >= low + 1 && arr[j] > pivot) j--;   // decrement j till we find an element smaller than / equal to pivot
        // 'i <= high - 1' and 'j >= low + 1' are written to avoid going out of array bounds after incrementing/decrementing i/j respectively.
        if(i < j) swap(arr[i], arr[j]);   // if i is still less than j, swap elements at i and j to put them in correct halves
    }
    
    swap(arr[low], arr[j]);   // swap pivot element with the element at j to place the pivot in its correct position
    return j;   // return the partition index, i.e., correct index of pivot element
}

void qs(vector<int>& arr, int low, int high) {
    // Base case: If array has zero or one element, it is already sorted. Thus, we return.
    if(low >= high) return;
    int partitionIndex = partition(arr, low, high);   // considering arr[low] as pivot
    qs(arr, low, partitionIndex - 1);
    qs(arr, partitionIndex + 1, high);
}

// T.C: O(nlogn);   where n = size of array.
//                  However, worst time complexity of quickSort is O(n^2), when pivot is chosen as the biggest element of array.
// S.C: O(1);   However, it occupies O(logn) recursive stack space, and worst case recursive stack space complexity can be O(n).
void quickSort(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    qs(arr, low, high);
}


int main() {
    vector<int> arr = {30, 40, 20, 70, 10, 60, 50};
    quickSort(arr);

    for(int element: arr) cout << element << " ";

    return 0;
}

// EXTRA INFO: Considering first array element as pivot is called Hoare's Partition Scheme, and considering last array element
//             as pivot is called Lomuto's Partition Scheme.
