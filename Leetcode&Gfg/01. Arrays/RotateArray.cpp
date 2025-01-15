// leetcode: 189. Rotate Array   --->   Given an integer array nums, rotate the array to the right by k steps,
// where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Modulus method
    // T.C: O(n)
    // S.C: O(n)
    void rotate_modulusMethod(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);

        for(int i = 0; i < n; i++) {
            temp[(i + k) % n]= nums[i];
        }

        nums = temp;
    }

// ------------------------------------------------------------------------------------

    // Reversal method: (0, n-1) -> (0, k-1) -> (k, n-1)
    // T.C: O(n)
    // S.C: O(1)
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();   // to handle the case when 'k > no.of elements in vector'
        // Note: In reverse function, reverse(start, end), the range is inclusive of start and exclusive of end.
        // reverse from (0, n-1)
        reverse(nums.begin(), nums.end());

        // reverse from (0, k-1)
        reverse(nums.begin(), nums.begin() + k);

        // reverse from (k, n-1)
        reverse(nums.begin() + k, nums.end());
    }
};


int main() {
    vector <int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Solution().rotate_modulusMethod(v, k);
    // for(auto it: v) cout << it << " ";

    Solution().rotate(v, k);
    for(auto it: v) cout << it << " ";

    return 0;
}
