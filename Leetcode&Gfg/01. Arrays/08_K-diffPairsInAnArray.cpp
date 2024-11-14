// Leetcode: 532. K-diff Pairs in an Array   --->   Given an array of integers nums and an integer k, return the number of
// unique k-diff pairs in the array.
// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
// • 0 <= i, j < nums.length
// • i != j
// • |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Example 1:
// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

// Example 2:
// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

// Example 3:
// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(m);   where m is the no.of unique pairs. In the worst case m = n^2.
    int findPairs_bruteforce(vector<int>& nums, int k) {
        set<vector<int>> st;

        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(abs(nums[i] - nums[j]) == k) {
                    vector<int> temp = {nums[i], nums[j]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }

// -----------------------------------------------------------------

    // Algorithm: Extremely simple (two pointer approach)
    // 1. Sort the array and initialize two pointers i and j on 0th and 1st index respectively.
    // 2. Calculate the difference between arr[j] and arr[i] until j reaches the end of array. So there can be 3 cases:
    //    Case 1: If diff > target:
    //            In this case, move i ahead to reduce the difference.
    //    Case 2: If diff < target:
    //            In this case, move j ahead to increase the difference.
    //    Case 3: If diff == target:
    //            In this case, store the pair {arr[i], arr[j]} in a set in order to calculate only unique pairs,
    //            and increment both i and j, to find a new pair.
    // 3. Return size of set.
    //    Edge case: It is given in the problem not to consider an element minus itself, if k = 0, i.e., i != j.
    //               So it may happen that k is given 0, and i and j both somehow came on the same element. In this
    //               case, increment j before going to next iteartion, so that i != j holds true always.
    // T.C: O(nlogn) + O(n) = O(nlogn)
    // S.C: O(m);   where m is the no.of unique pairs. In the worst case m = n^2.
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        int i = 0, j = 1;
        while (j < nums.size()) {
            int diff = nums[j] - nums[i];
            if(diff > k) i++;
            else if(diff < k) j++;
            else {   // if(diff == k)
                vector<int> temp = {nums[i], nums[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
                i++; j++;
            }
            if(i == j) j++;   // edge case
        }

        return st.size();
    }
};


int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    cout << Solution().findPairs_bruteforce(nums, k) << endl;
    cout << Solution().findPairs(nums, k);

    return 0;
}
