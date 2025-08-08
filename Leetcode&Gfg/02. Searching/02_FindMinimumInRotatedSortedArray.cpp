// Leetcode: 153. Find Minimum in Rotated Sorted Array   --->   Suppose an array of length n sorted in ascending order
// is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// • [4,5,6,7,0,1,2] if it was rotated 4 times.
// • [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1],
// a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Example 2:
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

// Example 3:
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.


// Algorithm: Extremely simple. Find the pivot element and return the element just after pivot. But make sure
//            to handle an edge case: return the first element if pivot element in at index 'nums.size() - 1'.
//            To know how to find pivot index in rotated sorted array, refer: 'BaseBuildingPrograms\04. Searching\04_FindPivotIndexInRotatedSortedArray.cpp'

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Returns the largest element in 'nums'
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

public:
    // T.C: O(logn)
    // S.C: O(1)
    int findMin(vector<int>& nums) {
        int pivotIndex = findPivotIndex(nums);

        // Smallest element will be always present just after the pivot index (index of largest element)
        if(pivotIndex == nums.size() - 1) return nums[0];   // if largest element is last element of array, first element is smallest
        return nums[pivotIndex + 1];
    }
};


int main() {
    vector <int> v = {18, 11, 13, 15, 17};

    cout << "Minimum element is: " << Solution().findMin(v);

    return 0;
}
