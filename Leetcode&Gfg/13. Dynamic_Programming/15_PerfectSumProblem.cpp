// GFG: Perfect Sum Problem   --->   Given an array arr of non-negative integers and an integer target, the task
// is to count all subsets of the array whose sum is equal to the given target.

// Example 1:
// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// Example 2:
// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

// Example 3:
// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.

// Example 4:
// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        
    }
};

int main() {
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;

    cout << Solution().perfectSum(arr, target);

    return 0;
}
