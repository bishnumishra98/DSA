// THOSE WHO DO NOT REMEMBER THE PAST ARE CONDEMNED TO REPEAT IT


// ✦ Dynamic programming(DP) is a method for solving complex problems by breaking them down into simpler subproblems.
// It is particularly useful for optimization problems where the solution can be built up from solutions to smaller
// instances of the same problem. Here are the key concepts and steps involved in dynamic programming:

// -> Optimal Substructure: The problem can be broken down into smaller, simpler subproblems, which can be solved
//                          independently. DP method of solving problems makes the solution easier to understand
//                          and implement by clearly defining subproblems and their interrelationships.

// -> Overlapping Subproblems: The problem has overlapping subproblems, meaning the same subproblems are solved
//                             multiple times. DP method of solving problem can help avoid these overlapping
//                             sub-problems, by storing intermediate results and avoiding redundant calculations.


// ✦ DP problems can be solved in either of the two ways:

// 1. Memoization (Top-Down Approach): Store the results of subproblems in a table to avoid redundant computations.
//                                     This involves solving the problem recursively and storing the results.
//                                     Steps involved in this process:
//                                     i.   Create a dp array.
//                                     ii.  Store/return answer in the dp array.
//                                     iii. If answer already exist in dp array, utilize the answer by returning it.

// 2. Tabulation (Bottom-Up Approach): Solve subproblems in a systematic way, typically using iteration, and store
//                                     their results in a table.
//                                     Steps involved in this process:
//                                     i.   Create a dp array.
//                                     ii.  Fill initial data in dp according to base case.
//                                     iii. Fill rest of the dp array using iteration.

// Although both approaches have same time complexity, the Tabulation (Bottom-Up Approach) is better
// as it uses iterative solution which saves overhead of recursive function calls.

// Example:
// Below is a fibonacci program to print nth number of the fibonacci series. f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2).
// nth number of fibonacci series can found out in both recursive and dynamic programming way:
// i)  Simple recursion (uses more space due to calling of same subproblems multiple times)
// ii) Dynamic programming (optimal solution)

#include <iostream>
#include <vector>
using namespace std;

// Simple recursion
// T.C: O(2^n)
// S.C: O(2^n);   due to recursive call stack
int fibo_recursion(int n) {
    // Base case
    if(n <= 1) return n;
    int ans = fibo_recursion(n - 1) + fibo_recursion(n - 2);
    return ans;
}

// ------------------------------------------------------------------------------------------------------------

int solve(int n, vector<int>& dp) {
    // Base case
    if(n <= 1) return n;

    // Step 3: If answer already exist in dp array, utilize the answer by returning it to avoid solving overlapping subproblems.
    if(dp[n] != -1) return dp[n];

    // Step 2: Store/return answer in the dp array.
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

// Memoization (Top-Down Approach)
// T.C: O(n)
// S.C: O(n) for dp array + O(n) for recursion stack space = O(n)
int fibo_memoization(int n) {
    // Step 1: Create a dp array of size 'n+1' with default values -1
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// ------------------------------------------------------------------------------------------------------------

// Tabulation (Bottom-Up Approach)
// T.C: O(n)
// S.C: O(n)
int fibo_tabulation(int n) {
    // Step 1: Create a 'dp' array of size 'n+1' with default values -1
    vector<int> dp(n + 1, -1);

    // Step 2: Fill initial data in dp according to base case.
    dp[0] = 0;
    // dp[1] = 1;   // this can also be used, but it will give heap-buffer-overflow if user input n = 0
    if(n >= 1) dp[1] = 1;   // that's why put it inside an if condition
    

    // Step 3: Fill rest of the dp array using iteration.
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// ------------------------------------------------------------------------------------------------------------

// Tabulation (Bottom-Up Approach) space optimised
// T.C: O(n)
// S.C: O(1)
int fibo_tabulation_SO(int n) {
    int prev2 = 0;
    if(n == 0) return prev2;   // to cover input n = 0.
    int prev = 1;

    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;   // although curr can also be returned, but returning prev covers the case of n = 1
}


int main() {
    // Fibo series elements: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
    int n = 6;

    cout << "Recursion: " << fibo_recursion(n) << endl;

    cout << "fibo_memoization: " << fibo_memoization(n) << endl;

    cout << "fibo_tabulation: " << fibo_tabulation(n) << endl;

    cout << "fibo_tabulation_SO: " << fibo_tabulation_SO(n);

    return 0;
}
