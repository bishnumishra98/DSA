// leetcode: 912. Sort an Array   --->   Given an array of integers nums, sort the array in ascending
// order and return it within O(nlogn) complexity.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

// This is question is of Merge Sort. So please go through 'MergeSort.cpp' present in 'BaseBuilding/Sorting'.

#include <iostream>
#include <vector>
using namespace std;

// void merge(vector<int>& nums, int start, int mid, int end) {
//     int *temp = new int[nums.size()];   // creating a 'temp' array of size 'nums.size()'
//     int left = start;
//     int right = mid+1;

//     int k = 0;
//     // comparing elements from both arrays and placing them in ascending order inside 'temp'
//     while(left<=mid && right<=end) {
//         if(nums[left] <= nums[right]) {
//             temp[k++] = nums[left++];
//         } else {
//             temp[k++] = nums[right++];
//         }
//     }

//     // if still elements are remaining in left array
//     while(left <= mid) {
//         temp[k++] = nums[left++];
//     }

//     // if still elements are remaining in right array
//     while(right <= end) {
//         temp[k++] = nums[right++];
//     }

//     // copy the sorted elements of 'temp' back to the original array
//     for(int i=start; i<=end; i++) {
//         nums[i] = temp[i-start];
//     }

//     delete[] temp;   // deallocating 'temp' from heap
// }

// void mergeSort(vector<int>& nums, int start, int end) {
//     // base case
//     if(start >= end) {
//         return;
//     }

//     int mid = start + (end-start)/2;

//     mergeSort(nums, start, mid);

//     mergeSort(nums, mid+1, end);

//     merge(nums, start, mid, end);
// }

// // T.C: O(nlogn)
// // S.C: O(n)
// vector<int> sortArray(vector<int>& nums) {
//     int start = 0;
//     int end = nums.size() - 1;
//     mergeSort(nums, start, end);
//     return nums;
// }

// int main() {
//     vector <int> v = {-2,3,-5};
//     vector <int> nums = sortArray(v);

//     for(int element: nums) {
//         cout << element << " ";
//     }

//     return 0;
// }

// The above code runs well, but as we are dynamically allocating and deallocating arrays in
// merge() function, this process can be computationally costly. When we use 'new' keyword to
// allocate memory (new int[nums.size()]), the OS must find and reserve a block of memory for
// our array. This operation involves additional bookkeeping for tracking allocated memory blocks,
// and there might be some overhead associated with memory management.
// In order to optimize this time, we must avoid allocation and deallocation of 'temp' array
// every time the merge() is called.

void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end) {
    int left = start;
    int right = mid+1;

    // 'temp' array is passed as reference. So 'temp' array has same size as that of 'nums'.
    // Therefore, it's size is unchanged. So don't make the mistake to initialize 'k' with 0.
    // Initialize 'k' with 'start'. Then we will copy elements from 'nums' to 'temp' in 
    // sorted order and finally copy those sorted values back to the original array.
    int k = start;
    // comparing elements from both arrays and placing them in ascending order inside 'temp'
    while(left<=mid && right<=end) {
        if(nums[left] <= nums[right]) {
            temp[k++] = nums[left++];
        } else {
            temp[k++] = nums[right++];
        }
    }

    // if still elements are remaining in left array
    while(left <= mid) {
        temp[k++] = nums[left++];
    }

    // if still elements are remaining in right array
    while(right <= end) {
        temp[k++] = nums[right++];
    }

    // copy the sorted elements of 'temp' back to the original array
    while(start <= end) {
        nums[start] = temp[start];
        start++;
    }
}

void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end) {
    // base case
    if(start >= end) {
        return;
    }

    int mid = start + (end-start)/2;

    mergeSort(nums, temp, start, mid);

    mergeSort(nums, temp, mid+1, end);

    merge(nums, temp, start, mid, end);
}

// T.C: O(nlogn)
// S.C: O(n)
vector<int> sortArray(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;

    vector <int> temp(nums.size(), 0);

    mergeSort(nums, temp, start, end);
    return nums;
}

int main() {
    vector <int> v = {-2, 3, -5};
    vector <int> nums = sortArray(v);

    for(int element: nums) {
        cout << element << " ";
    }

    return 0;
}