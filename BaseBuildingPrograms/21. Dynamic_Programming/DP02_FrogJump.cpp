// Problem link: https://www.naukri.com/code360/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Frog Jump   --->    There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth'
// stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair. If Frog jumps from 'ith' to 'jth' stair, the energy lost in the
// jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either
// to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from
// '1st' stair to 'Nth' stair.

// Example 1:
// Input:
// n = 4, heights = {10, 20, 30, 10}
// Output:
// 20
// Explanation:
// The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
// Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
// So, the total energy lost is 20 which is the minimum. Hence, the answer is 20.

// Example 2:
// Input:
// n = 3, heights = {10, 50, 10}
// Output:
// 0
// Explanation:
// The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
// So, the total energy lost is 0 which is the minimum. Hence, the answer is 0.

// Example 3:
// Input:
// n = 8, heights = {10, 20, 30, 40, 10, 40, 60, 50}
// Output:
// 40
// Explanation:
// There can be multiple paths like:
// 10 -> 20 -> 30 -> 40 -> 40 -> 50
// or, 10 -> 30 -> 40 -> 40 -> 50
// or, 10 -> 20 -> 40 -> 40 -> 50

// Constraints:
// 1 <= n <= 100000
// 1 <= heights[i] <= 1000

// This problem is very similar to 'Leetcode&Gfg\13. Dynamic_Programming\ClimbingStairs.cpp'.

// Algorithm: Think from top to bottom. If frog is at step 'n', it must have come from step 'n-1' or step 'n-2'. But as the
//            frog needs to come from minimum energy path, it should come from minimum energy paths amongst the above two paths.
//            Path 1: If it comes to 'n'th step from 'n-1'th path, the energy required to come from this path will be:
//                    minimum energy required to come till step 'n-1' + energy required to jump from step 'n-1' to 'n'.
//            Path 2: If it comes to 'n'th step from 'n-2'th path, the energy required to come from this path will be:
//                    minimum energy required to come till step 'n-2' + energy required to jump from step 'n-2' to 'n'.
//           The minimum energy required to come at 'n'th step will be min energy amongst path1 and path2.

#include <bits/stdc++.h>
using namespace std;

/*
int solve(int index, vector<int>& heights) {
    // Base cases:
    // 1) If n is 0, no energy is lost as the frog jumps to the same stair itself.
    if(index == 0) return 0;
    // 2) If n = 1, the only way frog can come to 1st step from 0th step is by spending heights[1] - heights[0] energy.
    if(index == 1) return abs(heights[1] - heights[0]);

    // Path 1 is left recursive call and Path 2 is right recursive call. Return the minimum energy paths amongst them.
    int left = solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = solve(index - 2, heights) + abs(heights[index] - heights[index - 2]);

    return min(left, right);
}
*/
// The above function having 2 base cases can be followed to write the recursive solution. But by chance, if the question is
// extended and the frog is allowed to jump 'k' steps; then we will have to write 'k' no.of base cases which is not feasible.
// Thus, it is beneficiary for us if we anyhow try to manage to write the recursive code using only 1 universal base case.

int solve(int index, vector<int>& heights) {
    // Base case: If frog is at index is 0, no energy is lost as the frog jumps to the same stair itself.
    if(index == 0) return 0;

    // Path 1 is left recursive call and Path 2 is right recursive call. Return the minimum energy paths amongst them.
    int left = solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;   // let right initially be INT_MAX, as we don't have any right branch for f(1).
    // So while calculating minimum enrgy to reach f(1), min(f(0) + energy required to jump from step 0 to 1, INT_MAX)
    // will give us f(0) + energy required to jump from step 0 to 1.
    if(index >= 2) right = solve(index - 2, heights) + abs(heights[index] - heights[index - 2]);   // 'if(index >= 2)' to avoid heap buffer overflow

    return min(left, right);
}

// T.C: O(2^n)
// S.C: O(2^n);   recursion stack space
int frogJump_recursion(int n, vector<int> &heights) {
    // The frog wants to jump from 1st to nth step. We have re-indexed it from 0th to 'n-1'th step as indexing in vector starts from 0.
    return solve(n - 1, heights);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

int solve(int index, vector<int>& heights, vector<int>& dp) {
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];   // if an answer for dp[index] exists in dp array, return the answer.

    int left = solve(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if(index >= 2) right = solve(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    dp[index] = min(left, right);   // store the minimum energy for reaching index 'index' in dp[index]
    return dp[index];
}

// T.C: O(n)
// S.C: O(n) for dp array + O(n) for recursion stack space = O(n)
int frogJump_memoization(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// T.C: O(n)
// S.C: O(n)
int frogJump_tabulation(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int index = 1; index < n; index++) {   // index runs from 0 to 'n-1' as we have re-indexed problem to 0 to 'n-1' steps.
        int left = dp[index - 1] + abs(heights[index] - heights[index - 1]);
        int right = INT_MAX;
        if(index >= 2) right = dp[index - 2] + abs(heights[index] - heights[index - 2]);
        dp[index] = min(left, right);
    }

    return dp[n - 1];
}

// ---------------------------------------------------------------------------------------------------------------------------------------

// T.C: O(n)
// S.C: O(1)
int frogJump_tabulation_SO(int n, vector<int> &heights) {
    int prev = 0;
    int prev2 = 0;   // prev2 is also 0, as we will need this while computing right initially, i.e., when index = 2.

    for(int index = 1; index < n; index++) {
        int left = prev + abs(heights[index] - heights[index - 1]);
        int right = INT_MAX;
        if(index >= 2) right = prev2 + abs(heights[index] - heights[index - 2]);
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
