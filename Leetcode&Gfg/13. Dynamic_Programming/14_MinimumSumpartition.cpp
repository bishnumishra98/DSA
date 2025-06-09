// Note: This problem looks similar to 'Leetcode&Gfg\05. Recursion\PartitionArrayIntoTwoArraysToMinimizeSumDifference.cpp',
//       but is slightly different. In that problem we were asked to partition the array in two equal lengths.
//       But here the array partitions can be of any length, i.e., the two partitions can contain unequal elements.
//       But the irony is, the solution for this problem is way too easier to understand than that one.

// GFG: Minimum sum partition   --->   Given an array arr[]  containing non-negative integers, the task is to
// divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and
// find the minimum difference.

// Example 1:
// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.

// Example 2:
// Input: arr[] = [1, 4]
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4
// Hence, minimum difference is 3.

// Example 3:
// Input: arr[] = [1]
// Output: 1
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {}, sum of Subset2 = 0
// Hence, minimum difference is 1.

// Problem link: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// Algorithm: The algorithm is based on 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
    }
};

int main() {
    vector<int> arr = {1, 6, 11, 5};
    
    cout << Solution().minDifference(arr);

    return 0;
}
