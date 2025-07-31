// Leetcode: 560. Subarray Sum Equals K   --->   Given an array of integers nums and an integer k, return the total
// number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

// Algorithm: Approach is somewhat similar to the algorithm of 'Leetcode&Gfg\01. Arrays\LongestSubarrayWithSumK.cpp'.
// Maintain a running prefix sum and use a hash map to store how often each prefix sum has occurred.
// If the current prefix sum is 'sum', and we previously saw 'sum - k', then there exists a subarray ending at the
// current index that sums to k.
// 1. Initialize a hashmap 'mp' that stores prefixSum till all indexes of the given 'arr', and frequency of prefixSum.
//    Also initialize a 'count' variable to store the count of subarrays having sum 'k'.
//    The prefixSum is the sum of all elements from the start of the array till the current index. Here, we will
//    store the first element in the hashmap always as 0, with frequency 1, meaning that the sum of elements before
//    the first element is 0, and it occurs once. mp[0] = 1 is actually for handling the case when prefix sum itself
//    is equal to k.
// 2. Traverse the array and for each element in the array:
//    i.   Calculate the prefixSum till that element.
//    ii.  Check if (sum - k) exists in mp:
//         → If yes, it means there are mp[sum - k] subarrays ending at current index with sum k. So, add mp[sum - k] to count.
//    iii. Increment the frequency of current prefix sum in mp, i.e., mp[sum]++
// 3.. Return the 'count'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Similar to optimised brute force of 'Leetcode&Gfg\01. Arrays\LongestSubarrayWithSumK.cpp'.
    // T.C: O(n^2)
    // S.C: O(1)
    int subarraySum_bruteforce(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }

// ----------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;   // {prefixSum -> frequency}
        mp[0] = 1;
        int preSum = 0, count = 0;

        for(int i = 0; i < n; i++) {
            preSum += nums[i];
            int complement = preSum - k;
            if(mp.find(complement) != mp.end()) count += mp[complement];
            mp[preSum]++;   // Keep this line at the end. Otherwise you will get wrong output for test cases like nums = {1}, k = 0.
            // If mp[preSum] doesn't exists, then C++ automatically inserts a default value of 0 for the key mp[prefixSum].
        }

        return count;
    }

    // ● Why mp[preSum]++ is required, why not simply mp[preSum] = 1 ?
    //   Dry run the test case: nums = [1, -1, 0], k = 0.
};


int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    // vector<int> nums = {1};
    // int k = 0;

    cout << Solution().subarraySum_bruteforce(nums, k) << endl;
    cout << Solution().subarraySum(nums, k);

    return 0;
}
