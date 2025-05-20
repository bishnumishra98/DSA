// This is an extension of the previous problem 'DP02_FrogJump.cpp'. The only difference
// being instead of at max 2 steps, the frog can jump at max k steps this time.

// Example 1:
// Input:
// n = 10, k = 3, heights = {10, 50, 30, 40, 10, 40, 60, 50, 20, 60}
// Output:
// 
// Explanation:
// 

// Algorithm:
// In the previous problem, when frog could jump at max 2 steps, there were 2 paths. Here when
// frog can jump at max k steps, there will be k paths to reach 'n - 1'th index of heights.

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int k, vector<int>& heights) {
    if(index == 0) return 0;

    /*
    int left = solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if(index >= 2) right = solve(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    return min(left, right);
    */

    // Generalizing the above lines of code:
    int minEnergy = INT_MAX;
    // Loop to try all possible jumps from '1' to 'k'
    for(int i = 1; i <= k; i++) {
        int jumpEnergy = INT_MAX;
        if(index >= i) jumpEnergy = solve(index - i, k, heights) + abs(heights[index] - heights[index - i]);   // generalised line
        minEnergy = min(minEnergy, jumpEnergy);
    }

    return minEnergy;
}

// T.C: O(2^n)
// S.C: O(2^n)
int frogJump_recursion(int n, int k, vector<int> &heights) {
    // The frog wants to jump from 1st to nth step. We have re-indexed it from 0th to 'n-1'th step as indexing in vector starts from 0.
    return solve(n - 1, k, heights);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

int solve(int index, int k, vector<int>& heights, vector<int>& dp) {
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int minEnergy = INT_MAX;
    // Loop to try all possible jumps from '1' to 'k'
    for(int i = 1; i <= k; i++) {
        int jumpEnergy = INT_MAX;
        if(index >= i) jumpEnergy = solve(index - i, k, heights) + abs(heights[index] - heights[index - i]);   // generalised line
        minEnergy = min(minEnergy, jumpEnergy);
    }

    dp[index] = minEnergy;
    return dp[index];
}

// T.C: O(n)
// S.C: O(n)
int frogJump_memoization(int n, int k, vector<int> &heights) {
    vector<int> dp(n, -1);
    return solve(n - 1, k, heights, dp);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// T.C: O(n)
// S.C: O(n)
int frogJump_tabulation(int n, int k, vector<int> &heights) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    // Loop through the array to fill the dp array
    for(int j = 1; j < n; j++) {
        int minEnergy = INT_MAX;
        // Loop to try all possible jumps from '1' to 'k'
        for(int i = 1; i <= k; i++) {
            int jumpEnergy = INT_MAX;
            if(j >= i) jumpEnergy = dp[j - i] + abs(heights[j] - heights[j - i]);   // generalised line
            minEnergy = min(minEnergy, jumpEnergy);
        }
        dp[j] = minEnergy;
    }
    
    return dp[n - 1];
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// Tabulation space optimization will require k variables to be made leading to O(k) space complexity. But in the
// worst case, if k = n, then the space complexity will be O(n). Thus, there is no benefit of space optimization.


int main() {
    vector<int> heights = {10, 50, 30, 40, 10, 40, 60, 50, 20, 60};
    int n = heights.size();
    int k = 3;

    cout << "frogJump_recursion: " << frogJump_recursion(n, k, heights) << endl;
    cout << "frogJump_memoization: " << frogJump_memoization(n, k, heights) << endl;
    cout << "frogJump_tabulation: " << frogJump_tabulation(n, k, heights);

    return 0;
}
