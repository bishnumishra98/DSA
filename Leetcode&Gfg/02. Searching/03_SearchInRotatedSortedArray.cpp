// Leetcode: 33. Search in Rotated Sorted Array   --->   There is an integer array nums sorted in ascending
// order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
// or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1


// Algorithm: Very simple. This question is divided into two sub questions:-

// 1) Find the pivot element in the rotated sorted vector so that we can divide the vector into 2 monotonic
//    functions. Refer: 'BaseBuildingPrograms\04. Searching\04_FindPivotIndexInRotatedSortedArray.cpp'

// 2) Then we will be able to apply binary search on each of the monotonic functions, i.e., each of the
//    two sorted parts of the vector; and finally find the target element.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findPivotIndex(vector<int>& nums) {
        int n =  nums.size();
        int start = 0, end = n - 1, mid = start + (end - start)/2;

        while(start <= end) {
            if(start == end) return start;   // if only 1 element is present in the array, then it itself is the pivot element

            if((mid + 1 < n) && (nums[mid] > nums[mid + 1])) return mid;
            else if((mid - 1 >= 0) && (nums[mid] < nums[mid - 1])) return mid - 1;
            else if(nums[mid] < nums[start]) end = mid - 1;
            else start = mid + 1;   // if(nums[mid] >= nums[start])

            mid = start + (end - start) / 2;
        }

        return -1;   // to avoid error 'function does not return a value in all control paths'
    }

    int findTargetIndexByBinarySearch(vector<int>& arr, int start, int end, int target) {
        int mid = start + (end - start) /2 ;

        while(start <= end) {
            if(target > arr[mid]) start = mid + 1;
            else if(target < arr[mid]) end = mid - 1;
            else return mid;   // if(target == arr[mid])

            mid = start + (end - start) / 2;
        }

        return -1;   // if target not found in array
    }

public:
    // T.C: O(logn)
    // S.C: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // Part 1: Finding pivot index so that we can divide array into 2 monotonic parts
        int pivotIndex = findPivotIndex(nums);   // T.C: O(logn), S.C: O(1)
        int ans = -1;

        // Part 2: Applying binary search in each of the two monotonic parts, i.e., line A and line B.
        // If target lies in line A, i.e., taller ascending slope
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = findTargetIndexByBinarySearch(nums, 0, pivotIndex, target);
        } else {
            // If target lies in line B, i.e shorter ascending slope
            ans = findTargetIndexByBinarySearch(nums, pivotIndex + 1, n - 1, target);
        }

        return ans;
    }
};


int main() {
    vector <int> v = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 0;

    cout << "Index of target is: " << Solution().search(v, target);

    return 0;
}
