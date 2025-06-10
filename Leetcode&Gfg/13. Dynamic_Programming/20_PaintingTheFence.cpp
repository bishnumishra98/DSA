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

// Algorithm: Think mathematically. If there are 2 posts and the first post can be colored in 'x' ways, and the
//            second post can be colored in 'y' ways. They both together can be colored in 'x * y' ways.
//            This is a fundamental principle of counting in combinatorics. Example:
//            Lets say the post P1 can be colored in two ways 'V' and 'I', and post P2 can be colored in three
//            ways 'B', 'G' and 'Y', respectively. Then the two posts can be colored in 2 * 3 = 6 ways.
//            The color combinations will be as follows: VB, VG, VY, IB, IG and IY.

//            Now in this problem, we are asked to find the number of ways in which we can paint 'n' posts with
//            'k' colors such that not more than 2 adjacent posts are of same color.
//            To solve this problem, call a function solve(n, k) which returns the total number of ways in which
//            'n' posts can be colored with 'k' colors such that not more than 2 adjacent posts are of same color.
//            Call the recursive function solve() for all 'n' posts and go deeper into the recursive tree until
//            there are only 1 post / 2 posts left.
//            1. The base cases of the recursion will be:
//               i)  If only 1 post is there: If there is only 1 post, it can be painted in any of the 'k' colors,
//                                            i.e., total ways to paint it is 'k'. Thus return k.
//               ii) If only 2 posts are there: If there are 2 posts, both posts can be painted in any of the 'k'
//                                              colors, i.e., total they can be painted in k^2 ways. Example:
//                                              Let the colors be RBG. Then the 2 posts can be colored in either
//                                              of the ways: RR, BB, GG, RB, RG, BR, BG, GR, GB. Thus, return k * k.
//            2. The body of recursion(solve(n, k)) will have only two simple options. We can either paint the 'n'th
//               and the 'n - 1'th post with different color, or we can paint both of them with the same color.
//               I)  Painting both posts with different colors:
//                   If we paint the 'n'th post a different color from the one before it('n - 1'th post),
//                   we have k - 1 choices (all colors except the previous post’s color) to paint the 'n'th post.
//                   The number of ways to paint the first n - 1 posts is given by solve(n - 1, k).
//                   This means to paint 'n - 1'th and 'n'th post differently, solve(n - 1, k) is multiplied by k - 1.
//               II) Paint both posts with same color:
//                   If the last two posts are the same color, they must differ from the post before them
//                   (the third-last post, i.e., 'n - 2'th post). Thus, we have k - 1 choices for the last two posts,
//                   and the number of ways to paint the first n - 2 posts is given by solve(n - 2, k).
//                   This means to paint 'n - 1'th and 'n'th post with same color, solve(n - 2, k) is multiplied by k - 1.
//            3. At the end, return the sum of both ways: painting both posts with different colors and painting
//               both posts with the same color.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k) { 
        if(n == 1) return k;
        if(n == 2) return k * k;

        // Ways in which last fence is of different color
        int ways1 = solve(n - 1, k) * (k - 1);

        // Ways in which last 2 fences are of same color
        int ways2 = solve(n - 2, k) * (k - 1);

        return ways1 + ways2;
    }

    // T.C: O(2^n)
    // S.C: O(n);   recursion stack space
    int countWays_recursion(int n, int k) {
        return solve(n, k);
    }

// -------------------------------------------------------------------------------------

int solve(int n, int k, vector<int>& dp) {   
        if(n == 1) return k;
        if(n == 2) return k * k;

        if(dp[n] != -1) return dp[n];

        int ways1 = solve(n - 1, k) * (k - 1);
        int ways2 = solve(n - 2, k) * (k - 1);

        return dp[n] = ways1 + ways2;
    }

    // T.C: O(n)
    // S.C: O(n) for dp array + O(n) for recursion stack space = O(n)
    int countWays_memoization(int n, int k) {
        vector<int> dp(n + 1, -1);
        return solve(n, k, dp);
    }

// -------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int countWays_tabulation(int n, int k) {
        vector<int> dp(n + 1, 0);

        // Base cases:
        dp[1] = k;
        dp[2] = k * k;

        for(int i = 3; i <= n; i++) {
            int ways1 = dp[i - 1] * (k - 1);
            int ways2 = dp[i - 2] * (k - 1);

            dp[i] = ways1 + ways2;
        }

        return dp[n];
    }

// -------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(1) 
    int countWays_tabulation_SO(int n, int k) {
        int prev2 = k;
        int prev1 = k * k;

        if(n == 1) return prev2;
        if(n == 2) return prev1;

        for(int i = 3; i <= n; i++) {
            int ways1 = prev1 * (k - 1);
            int ways2 = prev2 * (k - 1);

            int curr = ways1 + ways2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;   // or we can even return curr as both stands on same value after the above loop
    }
};


int main() {
    int n = 3, k = 2;

    cout << Solution().countWays_recursion(n, k) << endl;
    cout << Solution().countWays_memoization(n , k) << endl;
    cout << Solution().countWays_tabulation(n, k) << endl;
    cout << Solution().countWays_tabulation_SO(n, k);

    return 0;
}
