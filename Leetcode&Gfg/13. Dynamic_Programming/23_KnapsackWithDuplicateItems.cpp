// GFG: Knapsack with Duplicate Items   --->   Given a set of items, each with a weight and a value, represented
// by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Example 1:
// Input: val = [1, 1], wt = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.

// Example 2:
// Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 48
// Explanation: The optimal choice is to pick the 1st element 8 times.

// Example 3:
// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element .hence, total profit is 0.

// Constraints:
// 1 <= val.size() = wt.size() <= 1000
// 1 <= capacity <= 1000
// 1 <= val[i], wt[i] <= 100

// Problem link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// Algorithm: Again a very simple problem. Its just a variant of 'Leetcode&Gfg\13. Dynamic_Programming\18_01KnapSack.cpp'.
//            In that problem, the supply of items was limited. But here the supply of items are unlimited,
//            i.e., we can take any item multiple times in the knapsack.
//            Thus, we can apply same logic for infinite supply(remaining at same index even after taking the item).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int capacity, vector<int>& val, vector<int>& wt) {
        if(i == 0) {
            if(wt[0] <= capacity) return (capacity / wt[0]) * val[0];
            else return 0;
        }

        // At the current index, we have only two choices:
        // 1) Take the current item
        int take = INT_MIN;   // initially initialzed to 'INT_MIN', so that if 'wt[i] > capacity', the current item cannot be included
        if(wt[i] <= capacity) take = val[i] + solve(i - 1, capacity - wt[i], val, wt);

        // 2) Not take the current item
        int notTake = 0 + solve(i - 1, capacity, val, wt);

        return max(take, notTake);
    }

    int knapSack_recursion(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();   // no.of items
        return solve(n - 1, capacity, val, wt);
    }
};

int main() {
    vector<int> val = {6, 1, 7, 7}, wt = {1, 3, 4, 5};
    int capacity = 8;

    cout << Solution().knapSack_recursion(val, wt, capacity) << endl;

    return 0;
}
