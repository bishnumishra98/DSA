// Leetcode: 128. Longest Consecutive Sequence   --->   Given an unsorted array of integers nums, return the length of
// the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Example 3:
// Input: nums = [1,0,1,2]
// Output: 3

// Constraints:
// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: n(nlogn) + O(n) = O(nlogn)
    // S.C: O(1)
    int longestConsecutive_bruteforce(vector<int>& nums) {
        // Edge cases
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        sort(nums.begin(), nums.end());

        int length = 1, maxLength = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) continue;
            else if(nums[i] == nums[i - 1] + 1) {
                length++;
                maxLength = max(maxLength, length);
            }
            else if(nums[i] != nums[i - 1] + 1) length = 1;
        }

        return maxLength;
    }

// -------------------------------------------------------------------------------------------------------------

    // Optimal algorithm: The algorithm is very simple.
    // 1. Store all the elements in a set.
    // 2. Iterate through each element in the set.
    //    i.  For each element, check if the previous element (element - 1) is present in the set. If it is not present,
    //        it means that the current element is the starting point of a consecutive sequence.
    //    ii. Then keep checking for the next consecutive elements (element + 1, element + 2, ...) in the set until you
    //        reach an element that is not present, and also parallelly, keep counting the length of the sequence.
    //    iii. Update the maximum length of subsequence found so far.
    // 3. Finally, return the maximum length found.
    // The purpose of set in this algorithm is to allow O(1) average time complexity for checking the presence of an element,
    // which is crucial for achieving the O(n) time complexity of the algorithm.

    // T.C: O(n) + O(2n) for set = O(3n)
    // S.C: O(n)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;   // edge case

        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) st.insert(nums[i]);

        int maxLength = 1;

        for(auto it: st) {
            int curr = it;
            int length = 1;
            // If 'curr - 1' is not present in the set, it means 'curr' is the starting element of a sequence.
            if(st.find(curr - 1) == st.end()) {
                // Find the upcoming consecutive elements after 'curr' to find the length of the sequence starting from 'curr'.
                while(st.find(curr + 1) != st.end()) {
                    length++;
                    curr = curr + 1;
                }
                maxLength = max(maxLength, length);   // update the maximum length found so far
            }
        }

        return maxLength;
    }
};


int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << Solution().longestConsecutive_bruteforce(nums) << endl;
    cout << Solution().longestConsecutive(nums);

    return 0;
}
