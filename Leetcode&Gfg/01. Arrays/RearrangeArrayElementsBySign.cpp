// Leetcode: 2149. Rearrange Array Elements by Sign   --->   You are given a 0-indexed integer array nums of
// even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// 1. Every consecutive pair of integers have opposite signs.
// 2. For all integers with the same sign, the order in which they were present in nums is preserved.
// 3. The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Example 1:
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

// Example 2:
// Input: nums = [-1,1]
// Output: [1,-1]
// Explanation:
// 1 is the only positive integer and -1 the only negative integer in nums.
// So nums is rearranged to [1,-1].


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute force
    // T.C: O(2.5n)
    // S.C: O(2n)
    vector<int> rearrangeArray_bruteForce(vector<int>& nums) {
        int n = nums.size();
        vector <int> positive;
        vector <int> negative;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }

        vector <int> arr;

        for(int i=0; i<n/2; i++) {
            arr.push_back(positive[i]);
            arr.push_back(negative[i]);
        }

        return arr;
    }

// -------------------------------------------------------------

    // Two pointer approach
    // T.C: O(n)
    // S.C: O(n)
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int even = 0, odd = 1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                ans[even] = nums[i];
                even += 2;
            } else {   // if(nums[i] < 0)
                ans[odd] = nums[i];
                odd += 2;
            }
        }

        return ans;
    }
};


int main() {
    vector <int> v = {3, 1, -2, -5, 2, -4};

    // vector<int> ans = Solution().rearrangeArray_bruteForce(v);
    // for(auto it: ans) cout << it << " ";

    vector<int> ans = Solution().rearrangeArray(v);
    for(auto it: ans) cout << it << " ";

    return 0;
}
