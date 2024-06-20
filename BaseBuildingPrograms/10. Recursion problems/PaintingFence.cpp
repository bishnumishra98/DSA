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

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
using namespace std;

// T.C: O(2^n)
// S.C: O(n)
int getTotalWaysOfPainting(int n, int k) {
    // base case
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return k + k*(k-1);
    }

    int last2sameColorWays = (k-1)*getTotalWaysOfPainting(n-2, k);
    int last2differentColorWays = (k-1)*getTotalWaysOfPainting(n-1, k);

    return last2sameColorWays + last2differentColorWays;
    // or, we can write: return (k-1)*(getTotalWaysOfPainting(n-2, k) + getTotalWaysOfPainting(n-1, k));
}

int main() {
    int n = 4;
    int k = 3;

    cout << getTotalWaysOfPainting(n, k);

    return 0;
}
