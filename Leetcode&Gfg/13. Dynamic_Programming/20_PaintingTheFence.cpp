// GFG: Painting the Fence   --->   Given a fence with n posts and k colours, find out the number of ways of
// painting the fence so that not more than two consecutive posts have the same colours.
// Answers are guaranteed to be fit into a 32 bit integer.

// Example 1:
// Input: n = 3, k = 2 
// Output: 6
// Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
// 1. RRB
// 2. RBR
// 3. RBB
// 4. BRR
// 5. BRB
// 6. BBR

// Example 2:
// Input: n = 2, k = 4 
// Output: 16
// Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all
//              4 colors. Total possible combinations will be 4x4=16

// Constraints:
// 1 ≤ n ≤ 300
// 1 ≤ k ≤ 105

// Problem link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

// Algorithm:

#include <bits/stdc++.h>
using namespace std;

// T.C: O(2^n)
// S.C: O(n)
int getTotalWaysOfPainting_recursion(int n, int k) {
    // base case
    if(n == 1) return k;
    if(n == 2) return k + k*(k-1);
    
    // recursive solution
    return (k-1) * (getTotalWaysOfPainting_recursion(n-2, k) + getTotalWaysOfPainting_recursion(n-1, k));
}

// T.C: O(n);   Since each value from 1 to n is computed only once
// S.C: O(n);   The dp array of size n+1 is used to store the computed results for each subproblem, requiring O(n) space.
int getTotalWaysOfPainting_memoization(int n, int k, vector<int>& dp) {
    // base case
    if(n == 1) return k;
    if(n == 2) return k + k*(k-1);

    if(dp[n] != -1) return dp[n];
    
    dp[n] = (k-1) * (getTotalWaysOfPainting_memoization(n-2, k, dp) + getTotalWaysOfPainting_memoization(n-1, k, dp));
    return dp[n];
}

// T.C: O(n)
// S.C: O(n)
int getTotalWaysOfPainting_tabulation(int n, int k) {
    vector<int> dp(n+1, -1);

    dp[1] = k;
    dp[2] = k + k*(k-1);

    for(int i=3; i<=n; i++) {
        dp[i] = (k-1) * (dp[i-2] + dp[i-1]);
    }

    return dp[n];
}

// dp[i] depends on only 2 variables dp[i-2] and dp[i-1]. Thus, we can space optimize it further.
// T.C: O(n)
// S.C: O(1)
int getTotalWaysOfPainting_tabulation_SO(int n, int k) {
    int prev2 = k;
    int prev1 = k + k*(k-1);

    // base case
    if(n==1) return prev2;
    if(n==2) return prev1;

    int curr;
    for(int i=3; i<=n; i++) {
        curr = (k-1) * (prev2 + prev1);   // curr represents dp[i], prev2 represents dp[i-2] and prev1 represents dp[i-1], respectively.
        // update prev2 and prev1
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;   // or we can even return prev1 as both stands on same value after the bove loop
}

int main() {
    int n = 5;
    int k = 3;

    cout << "Recursion: " << getTotalWaysOfPainting_recursion(n, k) << endl;

    vector<int> dp(n+1, -1);
    cout << "Memoization: " << getTotalWaysOfPainting_memoization(n, k, dp) << endl;

    cout << "Tabulation: " << getTotalWaysOfPainting_tabulation(n, k) << endl;

    cout << "Tabulation_SO: " << getTotalWaysOfPainting_tabulation_SO(n, k) << endl;

    return 0;
}
