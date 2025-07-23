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

// ● What is a subarray ?
//   A subarray is a contiguous part of the array. Example:
//   For the arr: [1, 2, 3, 4, 5, 6]
//   Subarrays can be: [1] or [2] or [1, 2] or [1, 2, 3] or [2, 3] or [4, 5, 6], etc.
//   But [1, 3, 4] or [1, 3] or [2, 3, 5] cannot be called a subarray.

// Bruteforce algorithm: Generate all subarrays and find the longest one having sum k.
//                       1. Initialize a pointer 'i' at index 0 of the given 'arr', and a pointer 'j' that is initialized
//                          with each value of 'i'.
//                          Now 'i' will be used to iterate all elements of 'arr', and 'j' will be used to mark the index
//                          of the last element of the subarray that started from 'i', i.e., subarray ranges from index 'i'
//                          to index 'j'.
//                       2. Find the sum of elements of each subarray in the range 'i' to 'j', and keep a track of the
//                          length of the subarrays. The length of current subarray that ranges from 'i'th to 'j'th index
//                          is given by 'j - i + 1'.
//                       3. Update the maximum length of subarray whose sum is equal to k, and return it.

// Bruteforce optimization: The algorithm reamins the same, but we can optimize the way of finding sum of elements of each
//                          subarray in the range 'i' to 'j'.
//                          No need to calculate the sum everytime starting from index 'i'. One thing we know is the 'j'
//                          stands at 'i'th index initially for every new 'i'. Afterwards, 'j' starts moving till the index
//                          of the last element of the given 'arr'.
//                          Hence, initialize 'sum' to 0 for every new 'i', and just keep adding the elements pointed by 'j'
//                          to the 'sum' and keep checking if it is equal to k.

// Optimal algorithm: 

// ● Follow up question: If the array contains only positive integers, can you further optimize it ?
//   Answer: Yes, the problem can be further optimised if it contains only positive integers.
//   Algorithm for only positive integers:
//   

// Constraints:
// 1 ≤ arr.size() ≤ 10^5
// -10^4 ≤ arr[i] ≤ 10^4
// -10^9 ≤ k ≤ 10^9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: Little less than O(n^3)
    // S.C: O(1)
    int longestSubarray_bruteforce(vector<int>& arr, int k) {
        int maxLength = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i; j < arr.size(); j++) {
                int sum = 0;
                for(int x = i; x <= j; x++) sum += arr[x];   // sum of elements of the subarray that ranges from 'i' to 'j'
                if(sum == k) maxLength = max(maxLength, j - i + 1);   // update the maximum length of the subarray whose sum equals k
            }
        }

        return maxLength;
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(1)
    int longestSubarray_bruteforce_optimised(vector<int>& arr, int k) {
        int maxLength = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for(int j = i; j < arr.size(); j++) {
                sum += arr[j];   // sum of elements of the subarray that ranges from 'i' to 'j'
                if(sum == k) maxLength = max(maxLength, j - i + 1);   // update the maximum length of the subarray whose sum equals k
            }
        }

        return maxLength;
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n * logn);   considering ordered map. If we use unordered map, avg T.C would be O(n), but worst case can be O(n^2)
    // S.C: O(n)
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> prefixSum;
        int sum = 0;
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == k) maxLength = i + 1;
            int rem = sum - k;
            if(prefixSum.find(rem) != prefixSum.end()) {
                int length = i - prefixSum[rem];
                maxLength = max(maxLength, length);
            }
            if(prefixSum.find(sum) == prefixSum.end()) prefixSum[sum] = i;
        }

        return maxLength;
    }

// --------------------------------------------------------------------------------------------------------

};


int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << Solution().longestSubarray_bruteforce(arr, k) << endl;
    cout << Solution().longestSubarray_bruteforce_optimised(arr, k) << endl;

    return 0;
}
