// GFG: Subset Sum Problem   --->   Given an array of positive integers arr[] and a value sum, determine if there is a
// subset of arr[] with sum equal to given sum.

// Example 1:
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

// Example 2:
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.

// Example 3:
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        
    }
};

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << Solution().isSubsetSum(arr, sum);

    return 0;
}
