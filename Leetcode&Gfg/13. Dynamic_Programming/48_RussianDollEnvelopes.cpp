// Leetcode: 354. Russian Doll Envelopes   --->   You are given a 2D array of integers envelopes where
// envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// One envelope can fit into another if and only if both the width and height of one envelope are greater than the
// other envelope's width and height.
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// Note: You cannot rotate an envelope.

// Example 1:
// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

// Example 2:
// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1

// Algorithm: A cakewalk problem. It is just an extension of LIS problem 'Leetcode&Gfg\13. Dynamic_Programming\43_LongestIncreasingSubsequence.cpp'.
// 1. Sort the envelopes by width in increasing order. If two envelopes have the same width, sort them by height in
//    decreasing order.
// 2. After sorting, the problem reduces to finding the length of the longest increasing subsequence (LIS) based on height.

// ● Why to sort height in decreasing order when width is the same ?
//   - If we have two envelopes with the same width, we want to ensure that we do not count both of them in the LIS.
//     If we sorted by height in increasing order, we could end up counting both envelopes with the same width, which
//     would violate the condition that one envelope can fit into another only if both width and height are strictly greater.
//   - By sorting by height in decreasing order, we ensure that we only consider one of the envelopes with the same width,
//     thus maintaining the strictness required for the problem.
//   For more, try out dry run for: envelopes = [[4,5],[4,6],[6,7],[2,3],[1,1]];   correct o/p: 4
//   But if you don't sort height in decreasing order for same wdiths, then you will get an output of 5, which is wrong.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                // Find the index of the smallest number in 'temp' which is greater than or equal to 'nums[i]'.
                // lower_bound() returns an iterator to the first element that is not less than 'nums[i]'.
                // temp.begin() is subtracted from the iterator returned by lower_bound() to get the index.
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }

public:
    // T.C: O(n * log(n))
    // S.C: O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];   // height in decreasing order
            return a[0] < b[0];   // width in increasing order
        });

        int n = envelopes.size();
        vector<int> heights;
        for(int i = 0; i < n; i++) {
            heights.push_back(envelopes[i][1]);
        }

        return lengthOfLIS(heights);
    }
};

int main() {
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

    cout << Solution().maxEnvelopes(envelopes);

    return 0;
}
