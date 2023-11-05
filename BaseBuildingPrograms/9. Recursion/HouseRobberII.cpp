// leetcode: 213. House Robber II   --->   The question is same as House Robber, the only difference is
// that this time all houses are arranged in a circle.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
// because they are adjacent houses.

// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:
// Input: nums = [1,2,3]
// Output: 3

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int start, int end) {
    // base case
    if(start > end) {
        return 0;   // when 'start>end', there are no houses left to rob. So we can rob 0 money.
    }

    // There are only 2 choices in my hand, either I can rob a house or I cannot rob a house.
    // Case 1: If I rob at 'start' index, I will make nums[start] amount of money, and then I will rob
    // next to next house; that's why next call's starting index is 'start+2'
    int option1 = nums[start] + solve(nums, start+2, end);

    // Case 2: If I rob do not rob at 'start' index, I will make 0 money, but then I can rob
    // next house; that's why next call's starting index is 'start+1'
    int option2 = 0 + solve(nums, start+1, end);

    return max(option1, option2);
}

// T.C: O(2^n) + O(2^n) = O(2^n);   where n = nums.size()
// S.C: O(n)
int rob(vector<int>& nums) {
    int size = nums.size();

    if(size == 1) {   // if only 1 house is present, I can rob that
        return nums[0];
    }

    int start = 0;   // first index
    int end = size - 1;   // last index

    // When I am at the first house, I won't rob the last house as last house is just before the first
    // house. Thus, the array where I can rob exist only from the index '0' to 'second last index'.
    int ans1 = solve(nums, start, end-1);

    // When I am at the last house, I won't rob the first house as first house is just after the last
    // house. Thus, the array where I can rob exist only from the index '1' to 'last index'.
    int ans2 = solve(nums, start+1, end);

    return max(ans1, ans2);
}

int main() {
    vector <int> v = {2, 3, 2};
    cout << rob(v);

    return 0;
}