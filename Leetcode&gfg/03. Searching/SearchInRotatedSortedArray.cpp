// Leetcode: 33. Search in Rotated Sorted Array
// This problem is an implementation of binary search.

// This question is divided into two sub questions:-

// 1) Find the pivot element in the rotated sorted vector so that we can divide the vector into 2 monotonic
// functions. Refer: 'FindPivotIndexInRotatedSortedArray.cpp' in '4. Searching' in 'BaseBuildingPrograms'

// 2) Then we will be able to apply binary search on each of the monotonic functions, i.e each of the
// two sorted parts of the vector; and finally find the target element.


#include <iostream>
#include <vector>
using namespace std;

// Refer: 'FindPivotIndexInRotatedSortedArray.cpp' in '4. Searching' in 'BaseBuildingPrograms'
int findPivotIndex(vector<int>& nums) {
    int n =  nums.size();
    int start = 0, end = n - 1, mid = start + (end - start)/2;

    while(start <= end) {
        if(start == end) {   // if only 1 element is present in array
            return start;
        }

        if((mid+1 < n) && (nums[mid] > nums[mid+1])) {   // on pivot element
            return mid;
        } else if((mid-1 >= 0) && (nums[mid] < nums[mid-1])) {   // on element just next to pivot
            return mid-1;
        } else if(nums[mid] < nums[start]) {   // on line B, i.e shorter ascending slope
            end = mid - 1;
        } else {   // on line A, i.e ascending taller slope
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    // Returning a default value if none of the conditions are met
    return -1;
}

// Refer: 'BinarySearch.cpp' in '4. Searching' in 'BaseBuildingPrograms'
int findTargetIndexByBinarySearch(vector<int>& arr, int start, int end, int target) {
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(target == arr[mid]) {
            return mid;
        } else if(target > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;   // if target not found in array
}


// Leetcode given function
// T.C: O(logn)
// S.C: O(1)
int search(vector<int>& nums, int target) {
    int n = nums.size();
    // Part 1: Finding pivot index so that we can divide array into 2 monotonic parts
    int pivotIndex = findPivotIndex(nums);   // T.C: O(logn), S.C: O(1)
    int ans = -1;

    // Part 2: Applying binary search in each of the two monotonic parts, i.e line A and line B
    // if target lies in line A, i.e taller ascending slope
    if((target >= nums[0]) && (target <= nums[pivotIndex])) {
        ans = findTargetIndexByBinarySearch(nums, 0, pivotIndex, target);   // T.C: O(logn), S.C: O(1)
    } else {
        // if target lies in line B, i.e shorter ascending slope
        ans = findTargetIndexByBinarySearch(nums, pivotIndex+1, n-1, target);   // T.C: O(logn), S.C: O(1)
    }

    return ans;
}


int main() {
    vector <int> v = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 0;

    cout << "Index of target is: " << search(v, target);

    return 0;
}