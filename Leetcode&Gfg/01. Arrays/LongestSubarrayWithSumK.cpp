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

// Constraints:
// 1 ≤ arr.size() ≤ 10^5
// -10^4 ≤ arr[i] ≤ 10^4
// -10^9 ≤ k ≤ 10^9

// Problem link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


// ● What is a subarray ?
//   A subarray is a contiguous part of the array. Example:
//   For the arr: [1, 2, 3, 4, 5, 6]
//   Subarrays can be: [1] or [2] or [1, 2] or [1, 2, 3] or [2, 3] or [4, 5, 6], etc.
//   But [1, 3, 4] or [1, 3] or [2, 3, 5] cannot be called a subarray.


// Bruteforce algorithm: Generate all subarrays and find the longest one having sum k.
// 1. Initialize a pointer 'i' at index 0 of the given 'arr', and a pointer 'j' that is initialized
//    with each value of 'i'.
//    Now 'i' will be used to iterate all elements of 'arr', and 'j' will be used to mark the index
//    of the last element of the subarray that started from 'i', i.e., subarray ranges from index 'i'
//    to index 'j'.
// 2. Find the sum of elements of each subarray in the range 'i' to 'j', and keep a track of the
//    length of the subarrays. The length of current subarray that ranges from 'i'th to 'j'th index
//    is given by 'j - i + 1'.
// 3. Update the maximum length of subarray whose sum is equal to k, and return it.
//
// Bruteforce optimization:
// The algorithm reamins the same, but we can optimize the way of finding sum of elements of each
// subarray in the range 'i' to 'j'.
// No need to calculate the sum everytime starting from index 'i'. One thing we know is the 'j'
// stands at 'i'th index initially for every new 'i'. Afterwards, 'j' starts moving till the index
// of the last element of the given 'arr'.
// Hence, initialize 'sum' to 0 for every new 'i', and just keep adding the elements pointed by 'j'
// to the 'sum' and keep checking if it is equal to k.


// Optimal algorithm: The algorithm is simple and practical.
// Initialize a map 'prefixSum' to store the prefix sums. It will store the sum of elements from index 0
// to index 'i' as key, and the index 'i' as value.
// Illustration: arr = [10, 5, 2, 7, 1, -10], then prefixSum will be:
// {10: 0, 15: 1, 17: 2, 24: 3, 25: 4, 15: 5}
//
// The algorithm is based on the idea of reverse engineering.
// arr = [.  .  .  .  .  .  .  .  .  .]
// Index: 0  1  2  3  4  5  6  7  8  9
// Suppose the prefix sum till index 6 is 'sum', and prefix sum till index 2 is 'sum - k'. It means sum
// of elements from index 3 to index 6 will be sum - (sum - k) = k. Also, the length of subarray to form
// the sum k is 6 - 2 = 4, i.e., length of subarray = prefixSum[x] - prefixSum[x - k].
// Thus, the idea is we will keep on finding the prefix sums at every index, and if prefix sum at any index is
// equal to k, then a subarray is found of sum k for the first time. Store its length. But even if such a subarray
// is not found, do not worry, continue the iterations. When the prefix sums at indexes starts exceeding k, we will
// take advantage of reverse engineering to find the new subarrays of sum k. For reverse engineering, it is required
// to parallelly keep a track of (sum - k) at all indexes in a variable say 'rem'. At any index, if 'rem' is already
// present as an entry in the map, it means already a subarray with sum k existed till the index that corresponds
// to that entry in the map. So if (sum - k) is present at some index, and sum of elements till the current index
// is 'sum', a subarray with sum k is bound to be present till the current index. The subarray with sum k exists
// from the index 'prefixSum[rem] + 1' to 'prefixSum[sum]', and the length of this subarray will be
// 'prefixSum[sum] - prefixSum[rem]'.
//
// Let's look at an illustration to understand the algorithm:
// arr = [1, 3, 1, 1, 1, 1, 1, 5, 4, 2], k = 5
// Index: 0  1  2  3  4  5  6  7  8  9
//
// ● At i = 0, store {1, 0} in the map initially. rem = sum - k = 1 - 5 = -4. -4 is not yet present in map.
// ● At i = 1, store {4, 1} in the map. rem = sum - k = 4 - 5 = -1. -1 is not yet present in map.
// ● At i = 2, store {5, 2} in the map. A subarray is found of sum k at index 2, thus store its length in the
//   'maxLength' variable as (i + 1) = 2 + 1 = 3. No need of keep a track of rem for it, just move to next iteration.
// ● At i = 3, store {6, 3} in the map. rem = sum - k = 6 - 5 = 1. Now, 1 is already present in the map at index 0.
//   Thus, as (sum - k) is found at some index, a subarray with sum k is bound to be present at the current index.
//   The length of this subarray will be prefixSum[6] - prefixSum[1] = 3 - 0 = 3. As this length is not greater than
//   the existing 'maxLength' value, no need to update 'maxLength'. Move to next iteration.
// ● At i = 4, store {7, 4} in the map. rem = sum - k = 7 - 5 = 2. 2 is not yet present in map.
// ● At i = 5, store {8, 5} in the map. rem = sum - k = 8 - 5 = 3. 3 is not yet present in map.
// ● At i = 6, store {9, 6} in the map. rem = sum - k = 9 - 5 = 4. Now, 4 is already present in the map at index 1.
//   Thus, as (sum - k) is found at some index, a subarray with sum k is bound to be present at the current index.
//   The length of this subarray will be prefixSum[9] - prefixSum[4] = 6 - 1 = 5. As this length is greater than
//   the existing 'maxLength' value, update the 'maxLength'.
// ● At i = 7, store {14, 7} in the map. rem = sum - k = 14 - 5 = 9. Now, 9 is alreday present in the map at index 6.
//   Thus, the same logic and length of subarray will be prefixSum[14] - prefixSum[9] = 7 - 6 = 1. as it's not greater
//   than existing value of 'maxLength', no need to update it.
// ● At i = 8, store {18, 8} in the map. rem = sum - k = 18 - 5 = 13. 13 is not yet present in map.
// ● At i = 9, store {20, 9} in the map. rem = sum - k = 20 - 5 = 15. 15 is not yet present in map.
// Hence, at the end of all iterations, we get the maximum length of subarray with sum k is 5.


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

    // T.C: O(n);   considering unordered map; but worst case can be O(n^2). And if we use ordered map T.C would be O(logn) in all cases.
    // S.C: O(n)
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == k) {   // if a subarray with sum k found for the first time
                maxLength = i + 1;
                continue;   // optional, but better to write to speed up program
            }
            int rem = sum - k;
            // If 'rem' is already present in the map, it means a subarray with sum k is bound to be present
            // till the current index 'i'. The length of this subarray will be prefixSum[sum] - prefixSum[rem],
            // where prefixSum[sum] is the index of the current sum, i.e., 'i'.
            if(prefixSum.find(rem) != prefixSum.end()) {
                int length = i - prefixSum[rem];
                maxLength = max(maxLength, length);
            }
            // Add entry in the map only if the prefix sum is not already present in the map
            if(prefixSum.find(sum) == prefixSum.end()) prefixSum[sum] = i;
        }

        return maxLength;
    }

//  ● Why to add entry in the map only if the prefix sum is not already present in the map ?
//    Checking the sum is not already present in the map before adding its entry in map is important if
//    the given 'arr' contains 0s. If we do not check, the value of sum in the map gets overwritten by
//    new indexes which will give us incorrect length of longest subarray with sum k.
//    ● Illustration if we do not check if the prefix sum is not already present in the map before an entry:
//      arr = [2, 0, 0, 1, 1, 1], k = 3
//      Index: 0  1  2  3  4  5
//      - At i = 0, entry in map: {2, 0}
//      - At i = 1, entry in map: {2, 1}
//      - At i = 2, entry in map: {2, 2}
//      - At i = 3, entry in map: {3, 3},   maxLength = 3 + 1 = 4
//      - At i = 4, entry in map: {4, 4}
//      - At i = 5, entry in map: {5, 5},   rem = sum - k = 5 - 3 = 2. 2 is already present in the map at index 2.
//        hence, length of subarray = prefixSum[5] - prefixSum[2] = 5 - 2 = 3. As it's not greater than existing
//        'maxLength', thus 'maxLength' remains 4.
//        But it is completely wrong answer. The longest subarray was from index 1 to 5, i.e., of length 5.
//        To avoid this error, never overwrite the prefix in the map with a new index. We have to always store
//        the sum corresponding to the index where it occurred for the first time. By doing so, prefixSum[2] would
//        be 0, and length of subarray would be prefixSum[5] - prefixSum[2] = 5 - 0 = 5. In this way, we will be
//        able to include all the zeroes in the length of subarray.

// --------------------------------------------------------------------------------------------------------

// ● Follow up question: Can you generate longest subarray with sum k ?
//   Answer: yes, the code is very simple.

    // T.C: O(n);   considering unordered map; but worst case can be O(n^2). And if we use ordered map T.C would be O(logn) in all cases.
    // S.C: O(n)
    vector<int> printLongestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int maxLength = 0;

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == k) {   // if a subarray with sum k found for the first time
                maxLength = i + 1;
                ans.clear();   // always clear the ans vector before adding new elements
                for(int x = 0; x <= i; x++) ans.push_back(arr[x]);
                continue;   // optional, but better to write to speed up program
            }
            int rem = sum - k;
            // If 'rem' is already present in the map, it means a subarray with sum k is bound to be present
            // till the current index 'i'. The length of this subarray will be prefixSum[sum] - prefixSum[rem],
            // where prefixSum[sum] is the index of the current sum, i.e., 'i'.
            if(prefixSum.find(rem) != prefixSum.end()) {
                int length = i - prefixSum[rem];
                if(length > maxLength) {
                    maxLength = length;
                    ans.clear();
                    for(int x = prefixSum[rem] + 1; x <= i; x++) ans.push_back(arr[x]);
                }
            }
            // Add entry in the map only if the prefix sum is not already present in the map
            if(prefixSum.find(sum) == prefixSum.end()) prefixSum[sum] = i;
        }

        return ans;
    }

// --------------------------------------------------------------------------------------------------------
    
// ● Follow up question: If the array contains only positive integers, can you further optimize it ?
//   Answer: Yes, the problem can be further optimised if it contains only positive integers.
//   Algorithm: Extremely simple 2 pointer approach.
//   1. Initialize 2 pointers 'i' and 'j' at index 0 of the given 'arr'. The idea is to keep a track of sum of
//      elements from 'i + 1'th index to 'j'th index.
//   2. Now start moving 'j' and parallelly calculate prefix sums till each indexes of 'j'. If sum till 'j'th
//      index happen to be equal to k, the store the length of the subarray in 'maxLength', maxLength = j - i + 1.
//      As soon as the sum exceeds k, move ahead the 'i' pointer so that the sum shrinks, i.e., we will trim the
//      array from 0th index to 'i'th index so that the sum of elements in the range of 'j' to 'i + 1' decreases.
//      Move ahead 'i' until the sum comes within the range of k, i.e., until sum <= k. Then again move 'j' ahead,
//      and if the sum in the range of 'j'th index to 'i + 1'th index happen to be equal to k, again a subarray
//      with sum k is found. Update the 'maxLength' if a greater length of subarray is found.
//      In this way, keep iterating until 'j' crosses the index of the last element of the given 'arr'.
//      Pro tip: To calculate sum of elements from 'j'th index to 'i + 1'th index, don't run a loop unnecessarily.
//               Instead, whenever you move ahead 'j', add arr[j] to the sum; whenever you move ahead 'i', subtract
//               arr[i] from sum, i.e., apply sliding window technique.  

    // T.C: O(2n)
    // S.C: O(1)
    int longestSubarray_positives(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        int sum = arr[0];   // it's given in the problem that at least 1 element will be present in the array
        int maxLength = 0;

        while(j < n) {
            // If sum is greater than k, move ahead 'i' pointer until sum becomes less than or equal to k
            while(i <= j && sum > k) {
                sum -= arr[i];
                i++;
            }
            if(sum == k) maxLength = max(maxLength, j - i + 1);   // update the maximum length of the subarray whose sum equals k
            // Move ahead 'j' pointer to include next element in the sum
            j++;
            if(j < n) sum += arr[j];   // to avoid out of bounds error, check if j is still within the bounds of the array
        }

        return maxLength;
    }
};


int main() {
    // vector<int> arr = {10, 5, 2, 7, 1, -10};
    // int k = 15;

    vector<int> arr = {1, 3, 1, 1, 1, 1, 1, 5, 4, 2};
    int k = 5;

    // vector<int> arr = {2};
    // int k = 2;

    cout << Solution().longestSubarray_bruteforce(arr, k) << endl;
    cout << Solution().longestSubarray_bruteforce_optimised(arr, k) << endl;
    cout << Solution().longestSubarray(arr, k) << endl;
    vector<int> ans = Solution().printLongestSubarray(arr, k);
    for(auto it: ans) cout << it << " ";
    cout << endl;
    cout << Solution().longestSubarray_positives(arr, k);

    return 0;
}
