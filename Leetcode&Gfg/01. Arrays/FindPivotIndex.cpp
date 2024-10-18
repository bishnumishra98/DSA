// Leetcode: 724: Find Pivot Index   --->   Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all
// the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also
// applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

// Brute force algorithm:
// 1. Initialize two variables leftSum and rightSum with 0.
// 2. Starting from index 0 to n-1, calculate sum of all elements towards left of i and store it in leftSum. Similarly,
//    calculate sum of all elements towards right of i and store it in rightSum. If at any index, its leftSum and rightSum
//    is equal, return that index.

// Optimal algorithm:
// 1. Initialize two vectors leftSum and rightSum of size n, initialized with 0.
// 2. Build those arrays in the following way:
//    -> All elements of leftSum must indicate the sum of all elements towards its left.
//       Thus, its obvious that leftSum[0] would be 0.
//    -> All elements of rightSum must indicate the sum of all elements towards its right.
//       Thus, its obvious that rightSum[n-1] would be 0.
// 3. Iterate from index 0 to n-1, and compare elements of leftSum and rightSum with each other.
//    If at any index, element of leftSum is equal to element of rightSum, return that index.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(1)
    int pivotIndex_bruteforce(vector<int>& nums) {        
        for(int i = 0; i < nums.size(); i++) {
            int leftSum = 0, rightSum = 0;

            for(int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            for(int j = i+1; j < nums.size(); j++) {
                rightSum += nums[j];
            }

            if(leftSum == rightSum) return i;
        }
        
        return -1;
    }

    // T.C: O(n)
    // S.C: O(n)
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();      
        vector<int> leftSum(n, 0);
        vector <int> rightSum(n, 0);

        for(int i = 1; i < n; i++) {
            leftSum[i] = nums[i-1] + leftSum[i-1];   // leftSum[i] has sum of all elements towards left of i
        }

        for(int i = n-2; i >= 0; i--) {
            rightSum[i] = nums[i+1] + rightSum[i+1];   // rightSum[i] has sum of all elements towards right of i
        }

        for(int i = 0; i < n; i++) {
            if(leftSum[i] == rightSum[i]) return i;
        }

        return -1;
    }
};


int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << Solution().pivotIndex_bruteforce(nums) << endl << Solution().pivotIndex(nums);

    return 0;
}
