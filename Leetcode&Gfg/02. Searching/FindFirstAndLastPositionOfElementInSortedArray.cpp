// Leetcode: 34. Find First and Last Position of Element in Sorted Array   --->   Given an array of integers nums
// sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // T.C: O(logn)
    // S.C: O(1)
    int findFirstPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        int ans = -1;

        while(start <= end) {
            if(target == nums[mid]) {
                ans = mid;
                end = mid - 1;
            } else if(target > nums[mid]) {
                start = mid + 1;
            } else {   // if(target < nums[mid])
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return ans;
    }

    // T.C: O(logn)
    // S.C: O(1)
    int findLastPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        int ans = -1;

        while(start <= end) {
            if(target == nums[mid]) {
                ans = mid;
                start = mid + 1;
            } else if(target > nums[mid]) {
                start = mid + 1;
            } else {   // if(target < nums[mid])
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return ans;
    }

public:
    // T.C: O(logn) + O(logn) = O(logn)
    // S.C: O(1) + O(1) = O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPosition = findFirstPosition(nums, target);
        int lastPosition = findLastPosition(nums, target);

        vector <int> v;
        v.push_back(firstPosition);
        v.push_back(lastPosition);
        return v;
    }
};


int main() {
    vector <int> v = {5, 7, 7, 7, 8, 8, 10};
    int target = 7;

    vector <int> ans = Solution().searchRange(v, target);

    // Additional info
    cout << "\nTotal no.of occurrences of target: " << (ans.back() - ans.front() + 1);


    return 0;
}
