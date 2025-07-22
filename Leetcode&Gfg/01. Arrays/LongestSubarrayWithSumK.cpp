// GFG: Longest Subarray with Sum K   --->   Given an array arr[] containing integers and an integer k, your task is to
// find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no
// subarray with sum equal to k, return 0.

// Example 1:
// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest
// subarray with a sum of 15 is 6.

// Example 2:
// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

// Example 3:
// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].

// Algorithm: A subarray is a contiguous part of the array. Example:
//            For the arr: [1, 2, 3, 4, 5, 6]
//            Subarrays can be: [1] or [2] or [1, 2] or [1, 2, 3] or [2, 3] or [4, 5, 6], etc.
//            But [1, 3, 4] or [1, 3] or [2, 3, 5] cannot be called a subarray.

// Constraints:
// 1 ≤ arr.size() ≤ 10^5
// -10^4 ≤ arr[i] ≤ 10^4
// -10^9 ≤ k ≤ 10^9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
    }
};

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    return 0;
}
