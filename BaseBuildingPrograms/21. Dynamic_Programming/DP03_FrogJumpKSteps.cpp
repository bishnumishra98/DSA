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
// frog can jump at max k steps, there will be k paths to reach 'n-1'th index of heights.

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int>& heights) {
    // Base case: If the index is 0, no energy is lost as the frog jumps to the same stair itself.
    if(index == 0) return 0;

    // Path 1 is left recursive call and Path 2 is right recursive call. Return the minimum energy paths amongst them.
    int left = solve(index-1, heights) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;   // let right initially be INT_MAX, as we don't have any right branch for f(1).
    // So while calculating minimum enrgy to reach f(1), min(f(0) + energy required to jump from step 0 to 1, INT_MAX)
    // will give us f(0) + energy required to jump from step 0 to 1.
    if(index >= 2) right = solve(index-2, heights) + abs(heights[index] - heights[index-2]);   // 'if(index >= 2)' to avoid heap buffer overflow

    return min(left, right);
}

// T.C: O(2^n)
// S.C: O(2^n)
int frogJump_recursion(int n, vector<int> &heights) {
    // The frog wants to jump from 1st to nth step. We have re-indexed it from 0th to 'n-1'th step as indexing in vector starts from 0.
    return solve(n-1, heights);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

int solve(int index, vector<int>& heights, vector<int>& dp) {
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];   // if an answer for dp[index] exists in dp array, return the answer.

    int left = solve(index-1, heights, dp) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    if(index >= 2) right = solve(index-2, heights, dp) + abs(heights[index] - heights[index-2]);

    dp[index] = min(left, right);   // store the minimum energy for reaching index 'index' in dp[index]
    return dp[index];
}

// T.C: O(n)
// S.C: O(n)
int frogJump_memoization(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// T.C: O(n)
// S.C: O(n)
int frogJump_tabulation(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int index = 1; index < n; index++) {   // index runs from 0 to 'n-1' as we have re-indexed problem to 0 to 'n-1' steps.
        int left = dp[index-1] + abs(heights[index] - heights[index-1]);
        int right = INT_MAX;
        if(index >= 2) right = dp[index-2] + abs(heights[index] - heights[index-2]);
        dp[index] = min(left, right);
    }

    return dp[n-1];
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// T.C: O(n)
// S.C: O(1)
int frogJump_tabulation_SO(int n, vector<int> &heights) {
    int prev = 0;
    int prev2 = 0;   // prev2 is also 0, as we will need this while computing right initially, i.e., when index=2.

    for(int index = 1; index < n; index++) {
        int left = prev + abs(heights[index] - heights[index-1]);
        int right = INT_MAX;
        if(index >= 2) right = prev2 + abs(heights[index] - heights[index-2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}


int main() {
    vector<int> heights = {10, 20, 30, 40, 10, 40, 60, 50};
    int n = heights.size();

    cout << "frogJump_recursion: " << frogJump_recursion(n, heights) << endl;
    cout << "frogJump_memoization: " << frogJump_memoization(n, heights) << endl;
    cout << "frogJump_tabulation: " << frogJump_tabulation(n, heights) << endl;
    cout << "frogJump_tabulation_SO: " << frogJump_tabulation_SO(n, heights);

    return 0;
}
