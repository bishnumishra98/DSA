// gfg article: Given a fence with n posts and k colors, find out the number of ways of painting the fence such
// that at most 2 adjacent posts have the same color.

// Example 1:
// Input: n = 3, k = 2
// Output: 6
// Explanation: We have 3 posts and 2 colors. Let's say the two colors are Red(R) and Blue(B).
// Ways when last 2 posts have same color = 2 {RBB, BRR}.
// Ways when last 2 posts have different color = 4 {RRB, BBR, RBR, BRB}
// Ways when at most 2 posts have same color = 2 + 4 = 6 {RBB, BRR, RRB, BBR, RBR, BRB}

// Example 2:
// Input: n = 3, k = 3
// Output: 24
// Explanation: We have 3 posts and 3 colors. Let's say the three colors are Red(R), Blue(B) & Green(G).
// Ways when last 2 posts have same color = 6 {RGG, RBB, BRR, BGG, GRB, GBB}.
// Ways when last 2 posts have different color = 18 {RRB, RRG, BBR, BBG, GGR, GGB,
// RBR, RBG, RGR, RGB, BRB, BRG, BGR, BGB, GRB, GRG, GBR, GBG}
// Ways when at most 2 posts have same color = 6 + 18 = 24 {RGG, RBB, BRR, BGG, GRB, GBB,
// RRB, RRG, BBR, BBG, GGR, GGB, RGR, RGB, RBR, RBG, BRB, BRG, BGR, BGB, GRB, GRG, GBR, GBG}

// Example 3:
// Input: n = 2, k = 4
// Output: 16
// Explanation: We have 4 colors and 2 posts. Ways when both last 2 posts have same color = 4 
// Ways when last 2 posts have diff color = 12. Total = 4 + 12 = 16

// Please go through PaintingFence.jpg pic for understanding the recursive relation.

// Note: This problem was solved with recursion, but now we will solve it by dynamic programming for optimal solution.

#include <iostream>
#include <vector>
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
